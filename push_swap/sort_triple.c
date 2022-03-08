/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_triple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:44:24 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/21 19:47:29 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_tiple(t_vars *vars)
{
	int		max_pos;
	int		min_pos;

	max_pos = find_max(vars->na, vars->la);
	min_pos = find_min(vars->na, vars->la);

	/*ft_printf(BYEL "min: %d max: %d\n" RST, min_pos, max_pos);*/

	if (min_pos == 0 && max_pos == 1)
	{
		rra(vars, true);
		sa(vars, true);
	}
	else if (min_pos == 2 && max_pos == 0)
	{
		ra(vars, true);
		sa(vars, true);
	}
	else if (min_pos == 1 && max_pos == 2)
		sa(vars, true);
	else if (min_pos == 1 && max_pos == 0)
		ra(vars, true);
	else if (min_pos == 2 && max_pos == 1)
		rra(vars, true);
}

void	sort_triple_test(t_vars *vars)
{
	init(vars, (int []){1, 2, 3}, 3);
	sort_tiple(vars);
	init(vars, (int []){1, 3, 2}, 3);
	sort_tiple(vars);
	init(vars, (int []){2, 1, 3}, 3);
	sort_tiple(vars);
	init(vars, (int []){3, 1, 2}, 3);
	sort_tiple(vars);
	init(vars, (int []){2, 3, 1}, 3);
	sort_tiple(vars);
	init(vars, (int []){3, 2, 1}, 3);
	sort_tiple(vars);
}
