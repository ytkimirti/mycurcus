/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:12:20 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/27 13:38:01 by ykimirti         ###   ########.tr       */
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

# define SX 400
# define SY 200

# define GRAVITY 1

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
	void	*state;
}	t_data;

typedef struct s_state {
	int			xpos;
	int			ypos;
	int			xvel;
	int			yvel;
	char		*keys;
	char		*key_bit_positions;
	char		**map;
	int			map_width;
	int			map_height;
}				t_state;

typedef struct s_images
{
	void		*floor_images[10]; // 
	void		*player_idle[6]; // knight_idle_anim_f0 - 5
	void		*player_run[6]; // knight_idle_anim_f0 - 5
	void		*door_images[14]; // door_anim_opening_f0.png - 13
	void		*collectible_image;
}	t_images;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	void		**bg_images;
	t_data		*buf;
	t_state		*state;
	t_images	*images;
}				t_vars;

int		error_msg(char *msg); /* return 0, because it's an error*/

char	**read_map(char *filename, t_state *state);

int		close_application(t_vars *vars);

void	draw_square(t_data *data, int ox, int oy, int sx, int sy, int color);

void	my_pixelput(t_data *data, int x, int y, int color);

void	clear_line(void);

void	update_player(t_state *state);

void	player_jump(t_state *state);

#endif
