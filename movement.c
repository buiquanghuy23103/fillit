/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:38:44 by hbui              #+#    #+#             */
/*   Updated: 2022/01/08 12:02:49 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_top(int *tetrimino)
{
	tetrimino[SROW] = 0;
}
void	ft_left_incr(int *tetrimino)
{
	int k;

	k = -1;
	while (++k < 4)
		tetrimino[k] <<=  (tetrimino[SCOL] + 1);
	tetrimino[SCOL] = 0;
}

void	ft_left_scol(int *tetrimino)
{
	tetrimino[SCOL] = 0;
}

void	ft_left(int *tetrimino)
{
	int	max;
	int	k;
	int	longest;
	int	shift;

	max = ft_setbit(0, tetrimino[SIZE]);
	longest = 0;
	k = 0;
	shift = -1;
	while (k < 4)
	{
		if (tetrimino[k] > longest)
			longest = tetrimino[k];
		k++;
	}
	while (longest < max && ++shift > -1)
		longest = longest << 1;
	k = -1;
	while (++k < 4 && shift > 0)
		tetrimino[k] = tetrimino[k] << shift;
	tetrimino[SCOL] = 0;
}

void	ft_topleft_incr(int *tetrimino)
{
	ft_top(tetrimino);
	ft_left_incr(tetrimino);
	//ft_left(tetrimino);
}

void	ft_topleft_scol(int *tetrimino)
{
	ft_top(tetrimino);
	//ft_left(tetrimino);
	ft_left_scol(tetrimino);
}

void	ft_topleft(int *tetrimino)
{
	ft_top(tetrimino);
	ft_left(tetrimino);
}

int	ft_right(int *tetrimino)
{
	if (tetrimino[SCOL] + tetrimino[WIDTH] == tetrimino[SIZE])
			return (0);
	tetrimino[SCOL]++;
	return (1);
}

int	ft_down(int *tetrimino)
{
	if (tetrimino[SROW] + tetrimino[HEIGHT] >= tetrimino[SIZE])
		return (0);
	ft_left_scol(tetrimino);
	tetrimino[SROW]++;
	return (1);
}
