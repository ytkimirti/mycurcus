/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_minmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:43:22 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/21 19:43:23 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(int nums[], int len)
{
	int	min = INT_MAX;
	int	min_index;

	min_index = -1;
	while (len-- > 0)
	{
		if (nums[len] <= min)
		{
			min = nums[len];
			min_index = len;
		}
	}
	return (min_index);
}

int		find_max(int nums[], int len)
{
	int	max = INT_MIN;
	int	max_index;

	max_index = -1;
	while (len-- > 0)
	{
		if (nums[len] >= max)
		{
			max = nums[len];
			max_index = len;
		}
	}
	return (max_index);
}

