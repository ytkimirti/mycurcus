/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:22:51 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/14 16:23:21 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ra(t_vars *vars, bool print)
{
	int	first;
	int	i;

	if (vars->la < 2)
		return ;
	i = 0;
	first = vars->na[0];
	while (i < vars->la - 1)
	{
		vars->na[i] = vars->na[i + 1];
		i++;
	}
	vars->na[vars->la - 1] = first;
	render(vars, "ra", print);
}

void	rb(t_vars *vars, bool print)
{
	int	first;
	int	i;

	if (vars->lb < 2)
		return ;
	i = 0;
	first = vars->nb[0];
	while (i < vars->lb - 1)
	{
		vars->nb[i] = vars->nb[i + 1];
		i++;
	}
	vars->nb[vars->lb - 1] = first;
	render(vars, "rb", print);
}

void	rr(t_vars *vars, bool print)
{
	ra(vars, false);
	rb(vars, false);
	render(vars, "rr", print);
}
