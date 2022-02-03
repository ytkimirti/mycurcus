/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:12:20 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/03 13:25:43 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "colors.h"

# include "libmlx/mlx.h"
# include "libft/libft.h"

# include <stdbool.h>
/*# include <stdio.h>*/
# include <stdlib.h>
# include <string.h>
# include <errno.h>

// Original scale was 16
// Treat one pixel as 4
# define TILE_SIZE 64
# define LERP_SPEED 0.2
# define ENTITY_BOTTOM_OFFSET 12

# define FRAME_TIME 6
# define PLAYER_RUN_FRAME_TIME 23

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	KEY_ESCAPE	=53,
	KEY_LEFT	=123,
	KEY_RIGHT	=124,
	KEY_DOWN	=125,
	KEY_UP		=126,
	KEY_W		=13,
	KEY_A		=0,
	KEY_S		=1,
	KEY_D		=2,
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_state {
	int			ex;
	int			ey;
	int			esx;
	int			esy;

	int			px;
	int			py;
	int			psx;
	int			psy;
	int			move_count;
	bool		p_facing;
	int			p_timer;

	char		*keys;

	char		**map;
	int			map_width;
	int			map_height;
}				t_state;

typedef struct s_image
{
	void		*i;
	int			sx;
	int			sy;
}	t_image;

typedef struct s_images
{
	t_image		floor_images[5];
	t_image		wall_images[5];
	t_image		coin_images[4];
	t_image		player_idle[4];
	t_image		player_run[4];
	t_image		enemy_idle[4];
	t_image		enemy_run[4];
	t_image		ladder_image;
	t_image		collectible_image;
	t_image		point;
	t_image		digits[10];
	bool		is_player_running;
}	t_images;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			sx;
	int			sy;
	int			ox;
	int			oy;
	int			time;
	int			frame;
	t_data		buf;
	t_state		state;
	t_images	images;
}				t_vars;

int		error_msg(char *msg); /* return 0, because it's an error*/

char	**read_map(char *filename, t_state *state);

int		close_application(t_vars *vars);

void	game_over(t_vars *vars);

void	my_pixelput(t_data *data, int x, int y, int color);

void	clear_line(void);

void	update_player(t_vars *vars);

void	player_jump(t_state *state);

int		load_images(t_vars *vars);

void	render(t_vars *vars);

void	print_map(char **map);

void	reset_vars(t_vars *vars);

void	render_point(t_vars *vars, int sx, int sy);

void	move_player_to(t_vars *vars, int x, int y);

void	move_player_by(t_vars *vars, int x, int y);

void	move_enemy(t_vars *vars);

void	update_enemy(t_vars *vars);

void	set_enemy_pos(t_vars *vars);

bool	in_map(t_vars *vars, int x, int y);

char	find_char(t_vars *vars, int x, int y);

float	lerp(float a, float b, float t);

int		handle_keydown(int keycode, t_vars *vars);

int		handle_keyup(int keycode, t_vars *vars);

void	render_tiles(t_vars *vars, int x, int y, char c);

void	render_props(t_vars *vars, int x, int y, char c);

void	render_entities(t_vars *vars);

void	render_digits(t_vars *vars);

void	put_image(t_vars *vars, t_image *img, int x, int y);

// Loading
int		load_img(t_vars *vars, t_image *dest, char *path);

int		load_single(t_vars *vars, t_image *dest, char *path);

// Binary utils
int		set_bit(int bf, int n);

int		clr_bit(int bf, int n);

int		chk_bit(int bf, int n);

#endif
