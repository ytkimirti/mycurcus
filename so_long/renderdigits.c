/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderdigits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:41:25 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/03 13:40:57 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_digit(t_vars *vars, int digit, int xpos)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->images.digits[digit].i,
		vars->sx - (50 * (xpos + 1) + 10),
		10);
}

void	render_digits(t_vars *vars)
{
	int	num;
	int	i;

	num = vars->state.move_count;
	i = 0;
	if (num == 0)
	{
		render_digit(vars, 0, 0);
		return ;
	}
	while (num > 0)
	{
		render_digit(vars, num % 10, i);
		num /= 10;
		i++;
	}
}
