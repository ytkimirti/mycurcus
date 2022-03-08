/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:07:43 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/21 19:26:06 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

// DONT PUSH THIS SCRIPT

#include <stdio.h>
#include "push_swap.h"

void	get_number(t_vars *vars)
{
	char	*line;
	char	**nums;
	int		*ints;
	int		i;
	int		len;

	ft_printf(YEL "Enter numbers: " CYN);
	line = get_next_line(0);
	ft_printf(RST);
	nums = ft_split(line, ' ');

	i = 0;
	while (nums[i] != NULL)
		i++;
	len = i;
	ints = (int *)malloc(sizeof(int) * i);
	while (i-- > 0)
		ints[i] = ft_atoi(nums[i]);
	// Actually init it
	init(vars, ints, len);

	// Free mem
	i = 0;
	while (nums[i] != NULL)
		free(nums[i++]);
	free(nums);
	free(ints);
}

void	init_cli(t_vars *vars)
{
	char	*cmd;
	char	*line;

	cmd = "";
	while (ft_strncmp(cmd, "q", 9))
	{
		line = get_next_line(0);
		cmd = ft_substr(line, 0, ft_strlen(line) - 1);
		free(line);

		if (!ft_strncmp(cmd, "e", 99))
			get_number(vars);
		if (!ft_strncmp(cmd, "p", 99))
			render(vars, "print", true);
		else if (!ft_strncmp(cmd, "sa", 999))
			sa(vars, true);
		else if (!ft_strncmp(cmd, "sb", 999))
			sb(vars, true);
		else if (!ft_strncmp(cmd, "ss", 999))
			ss(vars, true);
		else if (!ft_strncmp(cmd, "ra", 999))
			ra(vars, true);
		else if (!ft_strncmp(cmd, "rb", 999))
			rb(vars, true);
		else if (!ft_strncmp(cmd, "rr", 999))
			rr(vars, true);
		else if (!ft_strncmp(cmd, "rra", 999))
			rra(vars, true);
		else if (!ft_strncmp(cmd, "rrb", 999))
			rrb(vars, true);
		else if (!ft_strncmp(cmd, "rrr", 999))
			rrr(vars, true);
		else if (!ft_strncmp(cmd, "pa", 999))
			pa(vars, true);
		else if (!ft_strncmp(cmd, "pb", 999))
			pb(vars, true);
		else
			ft_printf("\n");

		free(cmd);
	}
	ft_printf(BRED "Bye...\n" RST);
}
