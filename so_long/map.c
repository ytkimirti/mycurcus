/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:16:02 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/28 14:51:33 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
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

bool	confirm_map(char **map, t_state *state)
{
	int	row;
	int	col;
	int	seen_objects; /* If that object is seen, enables it as a bit. The result should be 0b00111 aka 7 */

	printf("%s", "\e[0;32m"); /* GREEN */
	printf("Checking map\n");
	printf("%s", "\e[0m"); /* RESET */

	printf("%s", "\e[0;36m"); /* CYAN */
	row = 0;
	seen_objects = 0;
	state->map_width = ft_strlen(map[0]); /* Reset the width */
	while (row < state->map_height)
	{
		col = 0;
		while (map[row][col] != 0 && map[row][col] != '\0')
		{
			if (((row == 0 || row == state->map_height - 1) && map[row][col] != '1') ||
				((col == 0 || col == state->map_width - 1) && map[row][col] != '1'))
				return (error_msg("The map must be surrounded by '1's."));
			if (map[row][col] == 'C')
				SET_BIT(seen_objects, 0);
			if (map[row][col] == 'E')
				SET_BIT(seen_objects, 1);
			if (map[row][col] == 'P')
			{
				state->px = col;
				state->py = row;
				SET_BIT(seen_objects, 2);
			}
			col++;
		}
		row++;
		if (state->map_width != col)
			return (error_msg("The map must be rectangular."));
		state->map_width = col;
	}
	if (seen_objects != 7)
		return (error_msg("There must be at least one C, E and P"));
	printf("Map width\t%d\nMap height\t%d\n", state->map_width, state->map_height);
	printf("%s", "\e[0m"); /* RESET */

	printf("%s", "\e[0;32m"); /* GREEN */
	printf("Map correct!\n");
	printf("%s", "\e[0m"); /* RESET */
	return (true);
}

void	print_map(char **map)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

char	**read_map(char *filename, t_state *state)
{
	char	*curr_line;
	int		fd;
	char	**map;
	int		i;

	printf("%s", "\e[0;32m"); /* GREEN */
	printf("Reading map: %s\n", filename);
	printf("%s", "\e[0m"); /* RESET */
	
	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		error_msg(strerror(errno));
		return (NULL);
	}
	i = 0;
	while (true)
	{
		curr_line = get_next_line(fd);
		if (!curr_line)
			break;
		curr_line[ft_strlen(curr_line) - 1] = '\0'; /* Trim the last \n character */
		map = add_to_list(map, curr_line, i + 1);
		if (!map)
			return (NULL);
		i++;
	}
	close(fd);
	state->map_height = i;
	if (!confirm_map(map, state))
	{
		error_msg("Map not correct!");
		free(map);
		return (NULL);
	}
	return (map);
}

