/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:15:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/03 13:38:18 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_enemy(t_vars *vars)
{
	vars->state.esx = lerp(
			vars->state.esx,
			vars->state.ex * TILE_SIZE,
			LERP_SPEED);
	vars->state.esy = lerp(
			vars->state.esy,
			vars->state.ey * TILE_SIZE,
			LERP_SPEED);
}

// Return true if successfull
static bool	move_enemy_by(t_vars *vars, int x, int y)
{
	char	c;
	int		tx;
	int		ty;

	if (x == 0 && y == 0)
		return (false);
	tx = vars->state.ex + x;
	ty = vars->state.ey + y;
	c = find_char(vars, tx, ty);
	if (c == '1')
		return (false);
	if (tx == vars->state.px && ty == vars->state.py)
		game_over(vars);
	vars->state.ex = vars->state.ex + x;
	vars->state.ey = vars->state.ey + y;
	return (true);
}

void	set_enemy_pos(t_vars *vars)
{
	char	c;
	int		x;
	int		y;
	int		i;

	c = '1';
	i = 0;
	while (c == '1')
	{
		x = (unsigned int)(i * 1274 + i * -4321 + 483) % vars->state.map_width;
		y = (unsigned int)(i * 38427 + i * -4543 + 84) % vars->state.map_height;
		c = vars->state.map[y][x];
		i++;
	}
	vars->state.ex = x;
	vars->state.ey = y;
}

// This gets executed after player has moved
// Try to move towards player. If failed 
void	move_enemy(t_vars *vars)
{
	int	dx;
	int	dy;

	if (vars->state.move_count % 2 == 0)
		return ;
	dx = (vars->state.px - vars->state.ex);
	if (dx > 0)
		dx = 1;
	else if (dx < 0)
		dx = -1;
	dy = (vars->state.py - vars->state.ey);
	if (dy > 0)
		dy = 1;
	else if (dy < 0)
		dy = -1;
	if (!move_enemy_by(vars, dx, 0) && !move_enemy_by(vars, 0, dy)
		&& !move_enemy_by(vars, 0, 1)
		&& !move_enemy_by(vars, 0, -1)
		&& !move_enemy_by(vars, 1, 0)
		&& !move_enemy_by(vars, -1, 0))
	{
		ft_printf(RED "ENEMY GOT STUCK\n" RST);
	}
}
