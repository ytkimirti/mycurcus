/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:11:22 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/01 18:13:19 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

float	lerp(float a, float b, float t)
{
	return (a + (b - a) * t);
}

char	find_char(t_vars *vars, int x, int y)
{
	if (!in_map(vars, x, y))
		return ('1');
	return (vars->state.map[y][x]);
}

bool	in_map(t_vars *vars, int x, int y)
{
	return (x >= 0
		&& y >= 0
		&& x < vars->state.map_width
		&& y < vars->state.map_height);
}
