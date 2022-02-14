/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:22:57 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/14 16:39:17 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	pa(t_vars *vars, bool print)
{
	int	i;
	if (vars->lb < 1)
	{
		render(vars, RED "pa cancelled > small" RST, print);
		return ;
	}
	vars->la++;
	i = vars->la - 1;
	while (i > 0)
	{
		vars->na[i] = vars->na[i - 1];
		i--;
	}
	vars->na[0] = vars->nb[0];
	i = 1;
	while (i < vars->lb)
	{
		vars->nb[i - 1] = vars->nb[i];
		i++;
	}
	vars->lb--;

	render(vars, "pa", print);
}

void	pb(t_vars *vars, bool print)
{
	int	i;
	if (vars->la < 1)
	{
		render(vars, RED "pb cancelled > small" RST, print);
		return ;
	}
	vars->lb++;
	i = vars->lb - 1;
	while (i > 0)
	{
		vars->nb[i] = vars->nb[i - 1];
		i--;
	}
	vars->nb[0] = vars->na[0];
	i = 1;
	while (i < vars->la)
	{
		vars->na[i - 1] = vars->na[i];
		i++;
	}
	vars->la--;

	render(vars, "pb", print);
}
