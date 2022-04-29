/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:47:42 by ykimirti          #+#    #+#             */
/*   Updated: 2022/03/08 17:26:07 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include "libft/libft.h"
#include "colors.h"
#include <stdbool.h>

#include <limits.h>

typedef struct
{
	int	la;
	int	lb;
	int	*na;
	int	*nb;
	bool print_lists;
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

int		find_min(int nums[], int len);
int		find_max(int nums[], int len);

// Sorters
void	sort_triple(t_vars *vars);
void	sort_triple_test(t_vars *vars);

void	sort_wheel(t_vars *vars);

#endif
