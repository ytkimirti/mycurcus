/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:15:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/01 18:52:07 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player(t_vars *vars)
{
	vars->state.psx = lerp(
			vars->state.psx,
			vars->state.px * TILE_SIZE,
			LERP_SPEED);
	vars->state.psy = lerp(
			vars->state.psy,
			vars->state.py * TILE_SIZE,
			LERP_SPEED);
	vars->state.p_timer--;
}

void	move_player_to(t_vars *vars, int x, int y)
{
	vars->state.px = x;
	vars->state.py = y;
}

bool	is_there_collectibles(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->state.map_height)
	{
		x = 0;
		while (x < vars->state.map_width)
		{
			if (vars->state.map[y][x] == 'C')
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

void	move_player_by(t_vars *vars, int x, int y)
{
	char	c;
	int		tx;
	int		ty;

	vars->state.p_timer = PLAYER_RUN_FRAME_TIME;
	vars->state.p_facing = x > 0;
	tx = vars->state.px + x;
	ty = vars->state.py + y;
	c = find_char(vars, tx, ty);
	if (c == '1')
		return ;
	if (c == 'C')
	{
		vars->state.map[ty][tx] = '0';
	}
	if (c == 'E' && !is_there_collectibles(vars))
	{
		close_application(vars);
	}
	move_player_to(vars, vars->state.px + x, vars->state.py + y);
}
