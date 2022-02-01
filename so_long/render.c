
#include "so_long.h"

void	put_image_lerp(t_vars *vars, t_image *img, int x, int y)
{
	img->x = img->x + ((x - img->x) * LERP_SPEED);
	img->y = img->y + ((y - img->y) * LERP_SPEED);

	mlx_put_image_to_window(vars->mlx, vars->win,
			img->i,
			img->x,
			img->y);
}

// X Y position is given from the top left cell index like 2 3
void	render_rectangular(t_vars *vars, t_image *img, int x, int y)
{
	x = x * TILE_SIZE;
	y = (y + 1) * TILE_SIZE;
	x += (TILE_SIZE - img->sx) / 2;
	y -= img->sy + ENTITY_BOTTOM_OFFSET;
	render_point(vars, 40, 40);
	mlx_put_image_to_window(vars->mlx, vars->win,
			img->i,
			x,
			y);
}

// XY in screen pixels
void	render_point(t_vars *vars, int sx, int sy)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
			vars->images.point.i,
			sx + 8,
			sy + 8);
}

void	render_entities(t_vars *vars)
{
	// Player
	render_rectangular(vars, &vars->images.player_run[vars->frame % 4],
			2,
			2);
			/*vars->state.px,*/
			/*vars->state.py);*/
	/*mlx_put_image_to_window(vars->mlx, vars->win,*/
			/*vars->images.player_run[vars->frame % 4].i,*/
			/*vars->state.px * TILE_SIZE,*/
			/*vars->state.py * TILE_SIZE);*/
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
		mlx_put_image_to_window(vars->mlx, vars->win,
				vars->images.wall_images[random % 5].i, tx, ty);
	}
	else
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->images.floor_images[random % 5].i, tx, ty);
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
		// RENDER DOOR
		mlx_put_image_to_window(vars->mlx, vars->win,
				vars->images.ladder_image.i, tx, ty);
	}
	else if (c == 'C')
	{
		// Render flask
		render_rectangular(vars, &vars->images.collectible_image, x, y);
		// Render coin
		/*mlx_put_image_to_window(vars->mlx, vars->win,*/
				/*vars->images.coin_images[vars->frame % 4].i, tx, ty);*/
	}
}

void	render_wrapper(t_vars *vars,
		void (*f)(t_vars *vars, int x, int y, char c))
{
	int		x;
	int		y;
	/*printf("h: %d w: %d\n", vars->state.map_height, vars->state.map_width);*/

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

void	render(t_vars *vars)
{
	render_wrapper(vars, render_tiles);
	render_wrapper(vars, render_props);
	render_entities(vars);
}
