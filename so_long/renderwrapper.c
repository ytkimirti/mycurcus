/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderwrapper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:08:33 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/01 18:10:44 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wrapper(t_vars *vars,
		void (*f)(t_vars *vars, int x, int y, char c))
{
	int		x;
	int		y;

	y = 0;
	while (y < vars->state.map_height)
	{
		x = 0;
		while (x < vars->state.map_width)
		{
			f(vars, x, y, vars->state.map[y][x]);
			x++;
		}
		y++;
	}
}

void	put_image(t_vars *vars, t_image *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		img->i,
		x + vars->ox,
		y + vars->oy);
}

void	render(t_vars *vars)
{
	render_wrapper(vars, render_tiles);
	render_wrapper(vars, render_props);
	render_entities(vars);
}
