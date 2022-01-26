/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:46:57 by hbui              #+#    #+#             */
/*   Updated: 2022/01/26 21:28:42 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_inil_tetr(t_tetr	*tetr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < MAXTETRIMINOS)
	{
		while (j < T_SIZE)
		{
			tetr->tmino[i][j] = 0;
			++j;
		}
		tetr->tmino[i][SIZE] = size;
		j = 0;
		++i;
	}
	tetr->tcount = 0;
}

void	ft_rm(int *dst, int *src, int *offbits)
{
	int	scol;

	scol = src[SCOL];
	offbits[src[SROW]] += src[B0];
	offbits[src[SROW] + 1] += src[B1];
	offbits[src[SROW] + 2] += src[B2];
	offbits[src[SROW] + 3] += src[B3];
	while (*src)
	{
		*dst ^= (*src << scol);
		dst++;
		src++;
	}
}

int	ft_add(int *dst, int *src, int *offbits)
{
	int	scol;

	scol = src[SCOL];
	offbits[src[SROW]] -= src[B0];
	offbits[src[SROW] + 1] -= src[B1];
	offbits[src[SROW] + 2] -= src[B2];
	offbits[src[SROW] + 3] -= src[B3];
	while (*src)
	{
		*dst |= (*src << scol);
		dst++;
		src++;
	}
	return (1);
}

void	ft_increment_size(t_tetr *s)
{
	int	i;
	int	j;
	int	*tetr0;

	tetr0 = s->tmino[0];
	i = tetr0[SIZE] + 1;
	j = 0;
	while (s->tcount * 4 > i * i || i < tetr0[HEIGHT] || i < tetr0[WIDTH])
		++i;
	while (j < MAXTETRIMINOS)
	{
		s->tmino[j][SIZE] = i;
		++j;
	}
}

int	ft_reset(t_tetr *storage, int *offbits, int *full)
{
	int	i;

	i = 0;
	storage->tmino[i][SROW] = 0;
	storage->tmino[i][EROW] = storage->tmino[i][HEIGHT];
	storage->tmino[i][SCOL] = 0;
	storage->tmino[i][ECOL] = storage->tmino[i][WIDTH];
	ft_increment_size(storage);
	*full = ft_setbit(0, storage->tmino[i][SIZE]) - 1;
	while (i < storage->tmino[i][SIZE])
	{
		offbits[i] = storage->tmino[i][SIZE];
		i++;
	}
	return (1);
}
