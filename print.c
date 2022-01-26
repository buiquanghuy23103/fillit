/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:51:41 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/26 21:23:10 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_init_printing(t_tetr *t)
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

static void	ft_apply_tetr_to_result(int *arr, char **p, int c)
{
	int	i;
	int	j;
	int	k;
	int	num;

	k = 0;
	i = arr[SROW];
	j = arr[SIZE] - 1;
	while (k < arr[HEIGHT])
	{
		num = arr[k] << arr[SCOL];
		while (j >= 0)
		{
			if (ft_getbit(num, j))
				p[i + k][j] = c;
			--j;
		}
		j = arr[SIZE] - 1;
		++k;
	}
}

void	ft_print_result(t_tetr *t, int index)
{
	char	**p;
	int		i;

	p = ft_init_printing(t);
	i = 0;
	while (i < index)
	{
		ft_apply_tetr_to_result(t->tmino[i], p, 'A' + i);
		++i;
	}
	i = 0;
	while (i < t->tmino[0][SIZE])
	{
		write(1, p[i], t->tmino[0][SIZE]);
		free(p[i]);
		++i;
		ft_putchar('\n');
	}
	free(p);
}
