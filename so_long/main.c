/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:06:29 by ykimirti          #+#    #+#             */
/*   Updated: 2022/04/29 13:44:23 by ykimirti         ###   ########.tr       */
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

int	update(t_vars *vars)
{
	vars->time++;
	vars->frame = vars->time / FRAME_TIME;
	update_player(vars);
	update_enemy(vars);
	render(vars);
	return (0);
}

void	game_over(t_vars *vars)
{
	ft_printf(RED "---- YOU LOST MUHHAHAHA ---\n" RST);
	close_application(vars);
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

void	init_mlx(t_vars *vars)
{
	vars->sx = vars->state.map_width * TILE_SIZE;
	vars->sy = vars->state.map_height * TILE_SIZE;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->sx, vars->sy, "So LOOONG");
	vars->buf.img = mlx_new_image(vars->mlx, vars->sx, vars->sy);
	vars->buf.addr = mlx_get_data_addr(vars->buf.img,
			&vars->buf.bits_per_pixel,
			&vars->buf.line_length,
			&vars->buf.endian);
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
	init_mlx(&vars);
	if (!load_images(&vars))
		exit(0);
	vars.state.keys = (char [256]){0};
	set_enemy_pos(&vars);
	mlx_hook(vars.win, ON_KEYDOWN, 0, handle_keydown, &vars);
	mlx_hook(vars.win, ON_KEYUP, 0, handle_keyup, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close_application, &vars);
	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_loop(vars.mlx);
	pause();
}
