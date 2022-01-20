/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitfields.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:23:44 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/20 15:53:31 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#define SET_BIT(BF, N) BF |= ((uint64_t)0x1 << N)

#define CLR_BIT(BF, N) BF &= ~((uint64_t)0x1 << N)
 
#define	CHK_BIT(BF, N) ((BF >> N) & 0x1)

int	main(void)
{
	printf("%uz\n", sizeof(   ));
}
