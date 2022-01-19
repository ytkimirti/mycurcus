/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:06:29 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/19 17:42:36 by ykimirti         ###   ########.tr       */
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
#include "fdf.h"
#include "mlx.h"
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

enum {
	KEY_ESCAPE=53
};

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

int	handle_keydown(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESCAPE)
	{
		printf("%s\n", "Closing window...\n");
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}
	printf("Keycode: %d p: %p\n", keycode, vars);
	return (0);
}

int	update(t_vars *vars)
{
	// Draw shit
	draw_square(vars->buf, 30, 30, 50, 40, 0x00FF0000);


	// Render
	mlx_put_image_to_window(vars->mlx, vars->win, vars->buf->img, 0, 0);

	return (0);
}

int	main(void)
{
	t_vars	vars;
	int		sx;
	int		sy;

	sx = 400;
	sy = 200;

	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, sx, sy, "Why  sdyou not running???");

	vars.buf->img = mlx_new_image(vars.mlx, sx, sy);

	vars.buf->addr = mlx_get_data_addr(vars.buf->img,
								&vars.buf->bits_per_pixel,
								&vars.buf->line_length,
								&vars.buf->endian);



	// Create hook for keydown
	mlx_key_hook(vars.win, handle_keydown, &vars);

	// Create the update functions
	mlx_loop_hook(vars.mlx, update, &vars);

	mlx_loop(vars.mlx);
}
