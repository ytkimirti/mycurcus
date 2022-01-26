/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:06:29 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/26 18:29:56 by ykimirti         ###   ########.tr       */
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
#include "mlx.h"
#include "libft/libft.h"

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

void	draw_player(t_vars *vars, t_state *state)
{
	draw_square(vars->buf, state->xpos - 20, state->ypos - 20, 40, 40, 0x00FF0000);
}

int	update(t_vars *vars)
{
	t_state	*state;

	// Init
	state = vars->state;

	// Draw bg
	draw_square(vars->buf, 0, 0, SX, SY, 0x00FFFFFF);


	update_player(state);

	// Draw
	draw_player(vars, state);

	// Render
	mlx_put_image_to_window(vars->mlx, vars->win, vars->buf->img, 0, 0);

	clear_line();

	for (int i = 0; i < 64; i++)
	{
		if (state->keys[i])
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	return (0);
}

int	handle_keydown(int keycode, t_vars *vars)
{
	vars->state->keys[keycode] = true;

	if (keycode == KEY_ESCAPE)
	{
		close_application(vars);
	}
	else if (keycode == KEY_UP)
	{
		player_jump(vars->state);
	}
	else {
		/*printf("Keycode: %d p: %p\n", keycode, vars);*/
	}

	return (0);
}

int	handle_keyup(int keycode, t_vars *vars)
{
	vars->state->keys[keycode] = false;

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
	char	**map;

	vars.state = calloc(1, sizeof(t_state));

	if (argc != 2)
		return (error_msg("usage: ./so_long <filename>"));
	// parse file
	map = read_map(argv[1], vars.state);
	if (!map)
		exit(0);

	// INIT MLX
	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, SX, SY, "Why  sdyou not running???");

	// INIT BUFFER IMAGE
	vars.buf = calloc(1, sizeof(t_data));

	vars.buf->img = mlx_new_image(vars.mlx, SX, SY);

	vars.buf->addr = mlx_get_data_addr(vars.buf->img,
								&vars.buf->bits_per_pixel,
								&vars.buf->line_length,
								&vars.buf->endian);

	// INIT STATE
	vars.state->xpos = SX / 2;

	// 256 possible key positions. Give it the keycode, than see the key position
	vars.state->keys = (char [256]){0};

	// INIT HOOKS

	// Create hook for keydown
	/*mlx_key_hook(vars.win, handle_keydown, &vars);*/
	mlx_hook(vars.win, ON_KEYDOWN, 0, handle_keydown, &vars);
	mlx_hook(vars.win, ON_KEYUP, 0, handle_keyup, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close_application, &vars);

	// Create the update functions
	mlx_loop_hook(vars.mlx, update, &vars);

	mlx_loop(vars.mlx);
}
