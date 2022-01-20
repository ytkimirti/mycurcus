/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:15:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/20 18:55:38 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	player_jump(t_state *state)
{
	state->yvel = 10;
}

void	update_player(t_state *state)
{
	// Update velocities
	state->yvel -= GRAVITY;


	// Update position
	state->ypos -= state->yvel;
	state->xpos += state->xvel;

	// Update collisions
	if (state->ypos >= SY - 20)
	{
		state->yvel = 0;
		state->ypos = SY - 20;
	}
}
