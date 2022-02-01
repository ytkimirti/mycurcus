/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:06:29 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/01 15:55:44 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Allowed functions
 * open read write close
 * malloc free
 * perror strerror
 * exit
 *
 * math library
 *
 *
 * You can use other functions for bonus part
*/
#include "so_long.h"
#include <sys/time.h>

void	draw_square(t_data *data, int ox, int oy, int sx, int sy, int color)
{
	for (int x = 0; x < sx; x++)
	{
		for (int y = 0; y < sy; y++)
		{
			my_pixelput(data,ox+ x,oy+ y, color);
		}
	}
}

int	update(t_vars *vars)
{
	vars->time++;
	vars->frame = vars->time / FRAME_TIME;

	draw_square(&vars->buf, vars->frame, 0, 40, 40, 0x00FFFFFF);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->buf.img, 0, 0);

	render(vars);

	return (0);
}

int	handle_keydown(int keycode, t_vars *vars)
{
	vars->state.keys[keycode] = true;

	if (keycode == KEY_ESCAPE)
	{
		close_application(vars);
	}
	else {
		/*printf("Keycode: %d p: %p\n", keycode, vars);*/
	}

	return (0);
}

int	handle_keyup(int keycode, t_vars *vars)
{
	vars->state.keys[keycode] = false;

	return (0);
}

int	close_application(t_vars *vars)
{
	printf("%s", "\e[0;31m"); /* RED */
	printf("%s\n", "Closing window...\n");
	printf("%s", "\e[0m"); /* RESET */
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	reset_vars(&vars);
	// PARSE MAP
	if (argc != 2)
		return (error_msg("usage: ./so_long <filename>"));
	vars.state.map = read_map(argv[1], &vars.state);
	if (!vars.state.map)
		exit(0);
	ft_printf("Tile size: %d\n", TILE_SIZE);
	vars.sx = vars.state.map_width * TILE_SIZE;
	vars.sy = vars.state.map_height * TILE_SIZE;

	vars.time = 0;
	vars.images.is_player_running = false;

	// INIT MLX
	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, vars.sx, vars.sy, "Why  sdyou not running???");

	// LOAD IMAGES
	if (!load_images(&vars))
		exit(0);

	// INIT BUFFER IMAGE
	vars.buf.img = mlx_new_image(vars.mlx, vars.sx, vars.sy);

	vars.buf.addr = mlx_get_data_addr(vars.buf.img,
								&vars.buf.bits_per_pixel,
								&vars.buf.line_length,
								&vars.buf.endian);

	// 256 possible key positions. Give it the keycode, than see the key position
	vars.state.keys = (char [256]){0};

	// INIT HOOKS

	// Create hook for keydown
	mlx_hook(vars.win, ON_KEYDOWN, 0, handle_keydown, &vars);
	mlx_hook(vars.win, ON_KEYUP, 0, handle_keyup, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close_application, &vars);

	// Create the update functions
	mlx_loop_hook(vars.mlx, update, &vars);

	mlx_loop(vars.mlx);
}
