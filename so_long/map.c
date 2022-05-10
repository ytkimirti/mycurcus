/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:16:02 by ykimirti          #+#    #+#             */
/*   Updated: 2022/05/10 15:52:45 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

char	**add_to_list(char **list, char *element, int new_len)
{
	char	**new_list;
	int		i;

	new_list = malloc(sizeof(char *) * new_len);
	if (!new_list)
	{
		free(list);
		return (NULL);
	}
	i = 0;
	while (i < new_len - 1)
	{
		new_list[i] = list[i];
		i++;
	}
	new_list[i] = element;
	free(list);
	return (new_list);
}

// Returns false on error
bool	check_char(t_state *state,
		int *seen_objects,
		int row, int col)
{
	if (!ft_strchr("01PEC", state->map[row][col]))
		return (error_msg("The map must only contain 01PEC characters!"));
	if ((
			(row == 0 || row == state->map_height - 1)
			&& state->map[row][col] != '1') ||
			((col == 0 || col == state->map_width - 1)
			&& state->map[row][col] != '1')
		)
		return (error_msg("The map must be surrounded by '1's."));
	if (state->map[row][col] == 'C')
		*seen_objects = set_bit(*seen_objects, 0);
	if (state->map[row][col] == 'E')
		*seen_objects = set_bit(*seen_objects, 1);
	if (state->map[row][col] == 'P')
	{
		state->px = col;
		state->py = row;
		*seen_objects = set_bit(*seen_objects, 2);
	}
	return (true);
}

bool	confirm_map(char **map, t_state *state)
{
	int	row;
	int	col;
	int	seen_objects;

	row = 0;
	seen_objects = 0;
	state->map_width = ft_strlen(map[0]);
	while (row < state->map_height)
	{
		col = 0;
		while (map[row][col] != 0 && map[row][col] != '\0')
		{
			if (!check_char(state, &seen_objects, row, col))
				return (false);
			col++;
		}
		row++;
		if (state->map_width != col)
			return (error_msg("The map must be rectangular."));
		state->map_width = col;
	}
	if (seen_objects != 7)
		return (error_msg("There must be at least one C, E and P"));
	ft_printf(CYN "Map correct!\n" RST);
	return (true);
}

bool	open_file(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		error_msg(strerror(errno));
		return (false);
	}
	return (true);
}

char	**read_map(char *filename, t_state *state)
{
	char			*curr_line;
	int				fd;
	static int		i;

	if (!open_file(filename, &fd))
		return (NULL);
	while (true)
	{
		curr_line = get_next_line(fd);
		if (!curr_line)
			break ;
		curr_line[ft_strlen(curr_line) - 1] = '\0';
		state->map = add_to_list(state->map, curr_line, i + 1);
		if (!state->map)
			return (NULL);
		i++;
	}
	close(fd);
	state->map_height = i;
	if (!confirm_map(state->map, state))
	{
		free(state->map);
		return (NULL);
	}
	return (state->map);
}
