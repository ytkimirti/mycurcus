/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:15:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/01 16:37:46 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	move_player_to(t_vars *vars, int x, int y)
{
	ft_printf("Moving player to (%d, %d)\n", x, y);
	vars->state.px = x;
	vars->state.py = y;
}

void	move_player_by(t_vars *vars, int x, int y)
{
	char	c;
	int		tx;
	int		ty;

	tx = vars->state.px + x;
	ty = vars->state.py + y;

	c = find_char(vars, tx, ty);

	if (c == '1')
		return ;
	if (c == 'C')
	{
		// Collect the collectible
		vars->state.map[ty][tx] = '0';
	}
	move_player_to(vars, vars->state.px + x, vars->state.py + y);
}
