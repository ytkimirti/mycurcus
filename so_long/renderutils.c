/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:56:30 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/01 18:35:43 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = ((y * data->line_length) + (x * (data->bits_per_pixel / 8)));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

int	new_color(unsigned char t,
		unsigned char r,
		unsigned char g,
		unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

/*int	get_t(int trgb)*/
/*{*/
	/*return ((trgb >> 24) & 0xFF);*/
/*}*/

/*int	get_r(int trgb)*/
/*{*/
	/*return ((trgb >> 16) & 0xFF);*/
/*}*/

/*int	get_g(int trgb)*/
/*{*/
	/*return ((trgb >> 8) & 0xFF);*/
/*}*/

/*int	get_b(int trgb)*/
/*{*/
	/*return (trgb & 0xFF);*/
/*}*/

void	clear_line(void)
{
	printf("\x1b[1F");
	printf("\x1b[2K");
}

/*void	draw_square(t_data *data, int ox, int oy, int sx, int sy, int color)*/
/*{*/
	/*for (int x = 0; x < sx; x++)*/
	/*{*/
		/*for (int y = 0; y < sy; y++)*/
		/*{*/
			/*my_pixelput(data,ox+ x,oy+ y, color);*/
		/*}*/
	/*}*/
/*}*/
