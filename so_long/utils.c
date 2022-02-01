/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:11:22 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/01 17:10:44 by ykimirti         ###   ########.tr       */
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
	return (
			x >= 0 &&
			y >= 0 &&
			x < vars->state.map_width &&
			y < vars->state.map_height
		   );
}

void	my_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = ((y * data->line_length) + (x * (data->bits_per_pixel / 8)));

	dst = data->addr + offset;

	*(unsigned int*)dst = color;

}

/*int new_color(int t, int r, int g, int b)*/
/*{*/
	/*return (t << 24 | r << 16 | g << 8 | b);*/
/*}*/

int	new_color(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	clear_line()
{
	printf("\x1b[1F"); // Move to beginning of previous line 
	printf("\x1b[2K"); // Clear entire line
}
