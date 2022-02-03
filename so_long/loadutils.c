/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:22:06 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/03 13:22:14 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_img(t_vars *vars, t_image *dest, char *path)
{
	dest->i = mlx_xpm_file_to_image(vars->mlx, path, &dest->sx, &dest->sy);
	if (!(dest->i))
		return (error_msg("Non existing image!"));
	return (1);
}

int	load_single(t_vars *vars, t_image *dest, char *path)
{
	ft_printf("%s", "\e[0;33m");
	ft_printf("Loading single file %s\n", path);
	ft_printf("%s", "\e[0m");
	return (load_img(vars, dest, path));
}
