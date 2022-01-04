/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:16:46 by hbui              #+#    #+#             */
/*   Updated: 2022/01/04 15:32:12 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_left(int *tetrimino, const unsigned int size)
{
	int	max;
	int	i;
	int	k;
	int	longest;
	int	shift;

	max = ft_setbit(0, size);
	i = 0;
	longest = 0;
	k = 0;
	shift = -1;
	while (i < 16 && !tetrimino[i])
		i++;
	while (k < 4)
	{
		if (tetrimino[i + k] > longest)
			longest = tetrimino[i + k];
		k++;
	}
	while (longest < max && ++shift > -1)
		longest = longest << 1;
	k = -1;
	while (++k < 4 && shift > 0)
		tetrimino[i + k] = tetrimino[i + k] << shift;
}
