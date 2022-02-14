/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:47:42 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/14 17:04:13 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include "libft/libft.h"
#include "colors.h"
#include <stdbool.h>

typedef struct
{
	int	la;
	int	lb;
	int	*na;
	int	*nb;
} t_vars;

void	render(t_vars *vars, char *move, bool print);

void	sa(t_vars *vars, bool print);
void	sb(t_vars *vars, bool print);
void	ss(t_vars *vars, bool print);

void	pa(t_vars *vars, bool print);
void	pb(t_vars *vars, bool print);

void	ra(t_vars *vars, bool print);
void	rb(t_vars *vars, bool print);
void	rr(t_vars *vars, bool print);

void	rra(t_vars *vars, bool print);
void	rrb(t_vars *vars, bool print);
void	rrr(t_vars *vars, bool print);

void	init_cli(t_vars *vars);

void	init(t_vars *vars, int args[], int len);

#endif
