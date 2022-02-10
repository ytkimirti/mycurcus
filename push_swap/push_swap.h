/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:47:42 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/10 16:04:54 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include "libft/libft.h"
#include "colors.h"
#include <stdbool.h>

// is_sub - Is this a subprocess? Like ss executing sa and sb
typedef struct
{
	int	la;
	int	lb;
	int	*na;
	int	*nb;
	bool is_sub;
} t_vars;

#endif
