/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:05:18 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/01 18:11:12 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	put_image_lerp(t_vars *vars, t_image *img, int x, int y)*/
/*{*/
	/*img->x = img->x + (((float)x - img->x) * LERP_SPEED);*/

	/*img->y = img->y + (((float)y - img->y) * LERP_SPEED);*/

	/*mlx_put_image_to_window(vars->mlx, vars->win,*/
			/*img->i,*/
			/*img->x,*/
			/*img->y);*/
/*}*/

// X Y position is given screen pos from the top left of img
void	render_rectangular(t_vars *vars, t_image *img, int x, int y)
{
	y += TILE_SIZE;
	x += (TILE_SIZE - img->sx) / 2;
	y -= img->sy + ENTITY_BOTTOM_OFFSET;
	render_point(vars, 40, 40);
	put_image(vars,
		img,
		x,
		y);
}

// XY in screen pixels
void	render_point(t_vars *vars, int sx, int sy)
{
	put_image(vars,
		&vars->images.point,
		sx + 8,
		sy + 8);
}

void	render_entities(t_vars *vars)
{
	t_image	*img;

	if (vars->state.p_timer > 0)
		img = &vars->images.player_run[vars->frame % 4];
	else
		img = &vars->images.player_idle[vars->frame % 4];
	render_rectangular(vars, img,
		vars->state.psx,
		vars->state.psy);
}

void	render_tiles(t_vars *vars, int x, int y, char c)
{
	int	tx;
	int	ty;
	int	random;

	random = (9999 * x + 8888 * y) + 233 * (x - 1);
	if (random % 100 < 80)
		random = 0;
	tx = x * TILE_SIZE;
	ty = y * TILE_SIZE;
	if (c == '1')
	{
		put_image(vars,
			&vars->images.wall_images[random % 5], tx, ty);
	}
	else
	{
		put_image(vars, &vars->images.floor_images[random % 5], tx, ty);
	}
}

void	render_props(t_vars *vars, int x, int y, char c)
{
	int	tx;
	int	ty;

	tx = x * TILE_SIZE;
	ty = y * TILE_SIZE;
	if (c == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->images.ladder_image.i, tx, ty);
	}
	else if (c == 'C')
	{
		render_rectangular(vars, &vars->images.collectible_image,
			x * TILE_SIZE,
			y * TILE_SIZE);
	}
}
