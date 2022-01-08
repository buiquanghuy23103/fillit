/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:46:57 by hbui              #+#    #+#             */
/*   Updated: 2022/01/08 13:59:44 by hbui             ###   ########.fr       */
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

void	ft_remove_piece(int *dst, int *src)
{
	int	col;

	col = src[SCOL];
	while (*src)
	{
		*dst ^= (*src >> col);
		src++;
		dst++;
	}
}

void	ft_place_piece(int *dst, int *src)
{
	int	col;

	col = src[SCOL];
	while (*src)
	{
		*dst |= (*src >> col);
		src++;
		dst++;
	}
}
