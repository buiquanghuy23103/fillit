/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:51:41 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/02/09 13:01:04 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_init_printing(int size)
{
	char	**p;
	int		i;

	i = 0;
	p = (char **)ft_memalloc(sizeof(char *) * size);
	if (!p)
		ft_error();
	while (i < size)
	{
		p[i] = (char *)ft_memalloc(sizeof(char) * (size + 1));
		if (!p[i])
		{
			while (i-- > 0)
				free(p[i]);
			ft_error();
		}
		ft_memset(p[i], '.', size);
		i++;
	}
	return (p);
}

static void	ft_apply_tetr_to_result(int *arr, char **p, int c, int size)
{
	int	i;
	int	j;
	int	k;
	int	num;

	k = 0;
	i = arr[SROW];
	j = size - 1;
	while (k < arr[HEIGHT])
	{
		num = arr[k] << arr[SCOL];
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

void	ft_print_result(t_tetr *t, int tcount, int size)
{
	char	**p;
	int		i;

	p = ft_init_printing(size);
	i = 0;
	while (i < tcount)
	{
		ft_apply_tetr_to_result(t->tmino[i], p, 'A' + i, size);
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
