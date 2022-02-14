/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:47:40 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/14 17:15:34 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"


void	render(t_vars *vars, char *move, bool print)
{
	int	i;

	if (!print)
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


