/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:04:14 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/03 12:07:32 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

// BITFIELD MACROS
/*#define SET_BIT(BF, N) BF |= ((int)0x1 << N)*/
/*#define CLR_BIT(BF, N) BF &= ~((int)0x1 << N)*/
/*#define CHK_BIT(BF, N) ((BF >> N) & 0x1)*/

int	set_bit(int bf, int n)
{
	return (bf | (0x1 << n));
}

int	clr_bit(int bf, int n)
{
	return (bf & ~(0x1 << n));
}

int	chk_bit(int bf, int n)
{
	return ((bf >> n) & 0x1);
}
