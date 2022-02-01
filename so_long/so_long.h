/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:12:20 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/01 17:02:35 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "libft/libft.h"


// BITFIELD MACROS

# define SET_BIT(BF, N) BF |= ((uint64_t)0x1 << N)
# define CLR_BIT(BF, N) BF &= ~((uint64_t)0x1 << N)
# define CHK_BIT(BF, N) ((BF >> N) & 0x1)

/*# define SX 400*/
/*# define SY 200*/
// Original scale was 16
// Treat one pixel as 4
# define LERP_SPEED 0.1
# define TILE_SIZE 64
# define ENTITY_BOTTOM_OFFSET 12

# define FRAME_TIME 6

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
	int			px;
	int			py;
	int			psx;
	int			psy;
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
} t_image;

typedef struct s_images
{
	t_image		floor_images[5];
	t_image		wall_images[5];
	t_image		coin_images[4];
	t_image		player_idle[4];
	t_image		player_run[4];
	t_image		ladder_image;
	t_image		collectible_image;
	t_image		point;
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

void	draw_square(t_data *data, int ox, int oy, int sx, int sy, int color);

void	my_pixelput(t_data *data, int x, int y, int color);

void	clear_line(void);

void	update_player(t_state *state);

void	player_jump(t_state *state);

int		load_images(t_vars *vars);

void	render(t_vars *vars);

void	print_map(char **map);

void	reset_vars(t_vars *vars);

void	render_point(t_vars *vars, int sx, int sy);

void	move_player_to(t_vars *vars, int x, int y);

void	move_player_by(t_vars *vars, int x, int y);

bool	in_map(t_vars *vars, int x, int y);

char	find_char(t_vars *vars, int x, int y);

#endif
