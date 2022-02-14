/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:22:42 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/14 16:39:00 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	rra(t_vars *vars, bool print)
{
	int	last;
	int	i;

	if (vars->la < 2)
	{
		render(vars, RED "rra cancelled > small" RST, print);
		return ;
	}
	last = vars->na[vars->la - 1];
	i = vars->la - 1;
	while (i > 0)
	{
		vars->na[i] = vars->na[i - 1];
		i--;
	}
	vars->na[0] = last;
	render(vars, "rra", print);
}

void	rrb(t_vars *vars, bool print)
{
	int	last;
	int	i;

	if (vars->lb < 2)
	{
		render(vars, RED "rrb cancelled > small" RST, print);
		return ;
	}
	last = vars->nb[vars->lb - 1];
	i = vars->lb - 1;
	while (i > 0)
	{
		vars->nb[i] = vars->nb[i - 1];
		i--;
	}
	vars->nb[0] = last;
	render(vars, "rrb", print);
}

void	rrr(t_vars *vars, bool print)
{
	rra(vars, false);
	rrb(vars, false);
	render(vars, "rrr", print);
}
