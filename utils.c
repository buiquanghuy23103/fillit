/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:46:57 by hbui              #+#    #+#             */
/*   Updated: 2022/01/12 09:58:56 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

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

char	**ft_inil_array(t_tetr *t)
{
	char	**p;
	int		i;

	i = 0;
	p = (char **)ft_memalloc(sizeof(char *) * t->tmino[0][SIZE]);
	if (!p)
		ft_error();
	while (i < t->tmino[0][SIZE])
	{
		p[i] = (char *)ft_memalloc(sizeof(char) * (t->tmino[0][SIZE] + 1));
		if (!p[i])
		{
			while (i-- > 0)
				free(p[i]);
			ft_error();
		}
		ft_memset(p[i], '.', t->tmino[0][SIZE]);
		i++;
	}
	return (p);
}

void	ft_rm(int *dst, int *src, int *offbits)
{
	int	scol;

	scol = src[SCOL];

	offbits[src[SROW]] += src[BITS0];
	offbits[src[SROW] + 1] += src[BITS1];
	offbits[src[SROW] + 2] += src[BITS2];
	offbits[src[SROW] + 3] += src[BITS3];
	while (*src)
	{
		*dst ^= (*src << scol);
		dst++;
		src++;
	}
}

void	ft_add(int *dst, int *src, int *offbits)
{
	int	scol;

	scol = src[SCOL];
	offbits[src[SROW]] -= src[BITS0];
	offbits[src[SROW] + 1] -= src[BITS1];
	offbits[src[SROW] + 2] -= src[BITS2];
	offbits[src[SROW] + 3] -= src[BITS3];
	while (*src)
	{
		*dst |= (*src << scol);
		dst++;
		src++;
	}
}

void	ft_reset_map(t_tetr *storage, int *offbits, int *full)
{
	int	i;

	i = 0;
	storage->tmino[i][SROW] = 0;
	storage->tmino[i][EROW] = storage->tmino[i][HEIGHT];
	storage->tmino[i][SCOL] = 0;
	storage->tmino[i][ECOL] = storage->tmino[i][WIDTH];
	ft_set_minsize(storage);
	*full = ft_setbit(0, storage->tmino[i][SIZE]) - 1;
	while (i < storage->tmino[i][SIZE])
	{
		offbits[i] = storage->tmino[i][SIZE];
		i++;
	}
}
