/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:51:21 by hbui              #+#    #+#             */
/*   Updated: 2022/01/04 14:14:53 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_top(int *tetrimino)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (tetrimino[0] > 0)
		return ;
	while (i < 16 && !tetrimino[i])
	{
		i++;
	}
	ft_memmove(tetrimino, tetrimino + i, sizeof(int) * (16 - i));
}
