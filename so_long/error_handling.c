/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:22:38 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/01 14:41:11 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *msg)
{
	printf("%s", "\e[0;31m"); /* RED */
	printf("ERR: %s\n", msg);
	printf("%s", "\e[0m"); /* RESET */
	return (0);
}

void	reset_vars(t_vars *vars)
{
	vars->sx = 9999;
	vars->sy = 9999;
	vars->time = 9999;
	vars->frame = 9999;
	vars->state.px = 9999;
	vars->state.py = 9999;
	vars->state.map_width = 9999;
	vars->state.map_height = 9999;

	vars->images.floor_images[0] = (t_image){.i=(void *)9999, .sx=9999, .sy=9999};
}
