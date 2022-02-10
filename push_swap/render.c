/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:47:40 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/10 16:09:10 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"


void	render(t_vars *vars, char *move)
{
	int	i;

	if (vars->is_sub)
		return ;
	ft_printf("- " MAG "%s" RST "\t-\n", move);
	/*ft_printf(CYN "a\t" CYN "b\n" RST);*/
	/*ft_printf(CYN "-\t" CYN "-\n" RST);*/

	i = 0;
	while (i < vars->la || i < vars->lb)
	{
		if (i < vars->la)
			ft_printf(GRN "%d\t" RST, vars->na[i]);
		else
			ft_printf(GRN "\t" RST);

		if (i < vars->lb)
			ft_printf(RED "%d\n" RST, vars->nb[i]);
		else
			ft_printf(RED "\n" RST);
		i++;
	}
}

void	sa(t_vars *vars)
{
	int	c;

	if (vars->la < 2)
		return;
	c = vars->na[0];
	vars->na[0] = vars->na[1];
	vars->na[1] = c;
	render(vars, "sa");
}
void	sb(t_vars *vars)
{
	int	c;

	if (vars->lb < 2)
		return;
	c = vars->nb[0];
	vars->nb[0] = vars->nb[1];
	vars->nb[1] = c;
	render(vars, "sb");
}

void	ss(t_vars *vars)
{
	vars->is_sub = true;
	sa(vars);
	sb(vars);
	vars->is_sub = false;
	render(vars, "ss");
}

void	pa(t_vars *vars)
{
	int	i;
	if (vars->lb < 1)
		return ;
	vars->la++;
	i = vars->la - 1;
	while (i > 0)
	{
		vars->na[i] = vars->na[i - 1];
		i--;
	}
	vars->na[0] = vars->nb[0];
	vars->lb--;
	render(vars, "pa");
}

int	main(void)
{
	t_vars	vars;

	vars.la = 2;
	vars.na = (int [100]){1, 2};

	vars.lb = 3;
	vars.nb = (int [100]){5, 6, 3};

	render(&vars, "init");

	pa(&vars);
	pa(&vars);
	pa(&vars);
}
