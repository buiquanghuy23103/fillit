/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:51:41 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/02/16 22:10:37 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**init(int size)
{
	char	**p;
	int		i;

	i = 0;
	p = (char **)ft_memalloc(sizeof(char *) * size);
	if (!p)
		error();
	while (i < size)
	{
		p[i] = (char *)ft_memalloc(sizeof(char) * (size + 1));
		if (!p[i])
		{
			while (i-- > 0)
				free(p[i]);
			error();
		}
		ft_memset(p[i], '.', size);
		i++;
	}
	return (p);
}

static void	apply(t_tetr tetr, char **p, int c, int size)
{
	int	i;
	int	j;
	int	k;
	int	num;

	k = 0;
	i = tetr.srow;
	j = size - 1;
	while (k < tetr.height)
	{
		num = tetr.bin[k] << tetr.scol;
		while (j >= 0)
		{
			if (ft_getbit(num, j))
				p[i + k][j] = c;
			--j;
		}
		j = size - 1;
		++k;
	}
}

void	print(t_tetr *t, int tcount, int size)
{
	char	**p;
	int		i;

	p = init(size);
	i = 0;
	while (i < tcount)
	{
		apply(t[i], p, 'A' + i, size);
		++i;
	}
	i = 0;
	while (i < size)
	{
		write(1, p[i], size);
		free(p[i]);
		++i;
		ft_putchar('\n');
	}
	free(p);
}
