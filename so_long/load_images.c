/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:03:41 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/03 13:40:33 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_range
{
	int	start;
	int	end;
}	t_range;

static int	load_from_array(t_vars *vars, t_image dest[], char *paths[])
{
	int		i;

	ft_printf("%s", "\e[0;33m");
	i = 0;
	while (paths[i])
	{
		ft_printf("i: %d Loading file %s\n", i, paths[i]);
		if (!load_img(vars, &dest[i], paths[i]))
			return (0);
		i++;
	}
	ft_printf("%s", "\e[0m");
	return (1);
}

static int	load_as_array(t_vars *vars,
		t_image dest[],
		char *prefix,
		t_range range)
{
	int		i;
	char	*path;

	ft_printf("%s", "\e[0;33m");
	i = 0;
	while (i <= range.end - range.start)
	{
		path = ft_sprintf("%s%d.xpm", prefix, i + range.start);
		ft_printf("i: %d Loading file %s\n", i, path);
		if (!load_img(vars, &dest[i], path))
			return (error_msg("Non existing image!"));
		free(path);
		i++;
	}
	ft_printf("%s", "\e[0m");
	return (1);
}

void	load_entity_images(t_vars *vars)
{
	load_as_array(vars, vars->images.enemy_idle,
		"./assets/masked_orc_idle_anim_f", (t_range){0, 3});
	load_as_array(vars, vars->images.enemy_run,
		"./assets/masked_orc_run_anim_f", (t_range){0, 3});
	load_as_array(vars, vars->images.player_idle,
		"./assets/knight_f_idle_anim_f", (t_range){0, 3});
	load_as_array(vars, vars->images.player_run,
		"./assets/knight_f_run_anim_f", (t_range){0, 3});
}

int	load_images(t_vars *vars)
{
	load_entity_images(vars);
	load_as_array(vars, vars->images.coin_images,
		"./assets/coin_anim_f", (t_range){0, 3});
	load_single(vars, &vars->images.ladder_image,
		"./assets/floor_ladder.xpm");
	load_as_array(vars, vars->images.floor_images,
		"./assets/floor_", (t_range){1, 5});
	load_as_array(vars, vars->images.digits,
		"./assets/", (t_range){0, 9});
	load_from_array(vars, vars->images.wall_images,
		(char *[]){
		"./assets/wall_left.xpm",
		"./assets/wall_mid.xpm",
		"./assets/wall_right.xpm",
		"./assets/wall_hole_1.xpm",
		"./assets/wall_hole_2.xpm",
		NULL});
	load_single(vars, &vars->images.collectible_image,
		"./assets/flask_big_blue.xpm");
	load_single(vars, &vars->images.point,
		"./debug/point.xpm");
	return (true);
}
