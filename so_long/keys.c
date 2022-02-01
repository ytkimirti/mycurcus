/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:01:30 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/01 18:01:31 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keydown(int keycode, t_vars *vars)
{
	vars->state.keys[keycode] = true;
	if (keycode == KEY_ESCAPE)
		close_application(vars);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move_player_by(vars, -1, 0);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_player_by(vars, 1, 0);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move_player_by(vars, 0, -1);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_player_by(vars, 0, 1);
	return (0);
}

int	handle_keyup(int keycode, t_vars *vars)
{
	vars->state.keys[keycode] = false;
	return (0);
}
