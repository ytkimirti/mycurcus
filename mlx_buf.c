/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:06:29 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/01 17:58:48 by ykimirti         ###   ########.tr       */
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

int	update(t_vars *vars)
{
	vars->time++;
	vars->frame = vars->time / FRAME_TIME;
	update_player(vars);
	render(vars);
	return (0);
}

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

int	close_application(t_vars *vars)
{
	ft_printf("%s", "\e[0;31m");
	ft_printf("%s\n", "Closing window...\n");
	ft_printf("%s", "\e[0m");
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	vars = (t_vars){0};
	if (argc != 2)
		return (error_msg("usage: ./so_long <filename>"));
	vars.state.map = read_map(argv[1], &vars.state);
	if (!vars.state.map)
		exit(0);
	vars.sx = vars.state.map_width * TILE_SIZE;
	vars.sy = vars.state.map_height * TILE_SIZE;

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
