/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_topleft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:08:28 by hbui              #+#    #+#             */
/*   Updated: 2022/01/04 10:45:25 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_top(int *tetrimino[])
{
	int	i;
	int	k;
	int	new[16];

	i = 0;
	k = 0;
	ft_bzero(new, 16);
	if (*tetrimino[0] > 0)
		return ;
	while (i < 16 && !*tetrimino[i])
	{
		i++;
	}
	while (i < 16 && *tetrimino[i])
	{
		new[k] = *tetrimino[i];
		k++;
		i++;
	}
	*tetrimino = new;
}

static void	ft_left(int *tetrimino[], const unsigned int size)
{
	int	max;
	int	i;

	max = ft_setbit(0, size);
	i = -1;
	while (*tetrimino[++i])
	{
		if (*tetrimino[i] >= max)
			return ;
	}
}

void	ft_topleft(int *tetrimino[], const unsigned int size)
{
	ft_top(tetrimino);
	ft_left(tetrimino, size);
}
