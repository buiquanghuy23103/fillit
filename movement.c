/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:38:44 by hbui              #+#    #+#             */
/*   Updated: 2022/01/07 13:20:50 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_top(int *tetrimino)
{
	tetrimino[SROW] = 0;
}

void	ft_left(int *tetrimino)
{
	int	max;
	int	i;
	int	k;
	int	longest;
	int	shift;

	max = ft_setbit(0, tetrimino[SIZE]);
	i = tetrimino[SROW];
	longest = 0;
	k = 0;
	shift = -1;
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

void	ft_topleft(int *tetrimino)
{
	ft_top(tetrimino);
	ft_left(tetrimino);
}

int	ft_right(int *tetrimino)
{
	int	k;
	int	i;

	k = -1;
	i = tetrimino[SROW];
	while (++k < 4)
		if (tetrimino[i + k] % 2 != 0)
			return (0);
	k = -1;
	while (++k < 4)
		tetrimino[i + k] >>= 1;
	return (1);
}

int	ft_down(int *tetrimino)
{
	if (tetrimino[SROW] + tetrimino[HEIGHT] > tetrimino[SIZE])
		return (0);
	ft_left(tetrimino);
	tetrimino[SROW]++;
	return (1);
}
