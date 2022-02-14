/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:21:06 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/14 16:37:27 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sa(t_vars *vars, bool print)
{
	int	c;

	if (vars->la < 2)
	{
		render(vars, RED "sa cancelled > small" RST, print);
		return ;
	}
	c = vars->na[0];
	vars->na[0] = vars->na[1];
	vars->na[1] = c;
	render(vars, "sa", print);
}

void	sb(t_vars *vars, bool print)
{
	int	c;

	if (vars->lb < 2)
	{
		render(vars, RED "sb cancelled > small" RST, print);
		return ;
	}
	c = vars->nb[0];
	vars->nb[0] = vars->nb[1];
	vars->nb[1] = c;
	render(vars, "sb", print);
}

void	ss(t_vars *vars, bool print)
{
	sa(vars, false);
	sb(vars, false);
	render(vars, "ss", print);
}
