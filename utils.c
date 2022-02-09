/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:46:57 by hbui              #+#    #+#             */
/*   Updated: 2022/02/09 12:50:19 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_init_storage(t_tetr	*tetr)
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

int	ft_reset(t_tetr *storage, int *offbits, int *full, int *size)
{
	int	i;

	i = 0;
	storage->tmino[i][SROW] = 0;
	storage->tmino[i][EROW] = storage->tmino[i][HEIGHT];
	storage->tmino[i][SCOL] = 0;
	storage->tmino[i][ECOL] = storage->tmino[i][WIDTH];
	(*size)++;
	*full = ft_setbit(0, *size) - 1;
	while (i < *size)
	{
		offbits[i] = *size;
		i++;
	}
	return (1);
}
