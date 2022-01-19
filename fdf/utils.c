/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:11:22 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/19 13:22:19 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"


void	my_pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));

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
