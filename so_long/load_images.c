/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:03:41 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/27 13:51:57 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_as_array(t_vars *vars, void *dest[], char *prefix, int count, int start)
{
	int		i;
	char	*path;
	int		width;
	int		height;

	printf("%s", "\e[0;33m"); /* YELLOW */
	i = 0;
	while (i < count)
	{
		path = ft_sprintf("%s%d.png", prefix, i);
		ft_printf("Loaded file: %s\n", path);
		/*dest[i] = mlx_xpm_file_to_image(vars->mlx, path, &width, &height);*/
		free(path);
		i++;
	}
	printf("%s", "\e[0m"); /* RESET */

	return (1);
}

int	load_images(t_vars *vars)
{
	t_images	*img;
	img = ft_calloc(1, sizeof(vars->images));
	vars->images = img;
	load_as_array(vars, img->floor_images, "./assets/tiles/floor/floor_", 10, 1);

	return (1);
}

