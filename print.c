/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:51:41 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/09 19:52:45 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_tetrimino(int *arr, char **p, int c)
{
	int	i;
	int	j;
	int k;
	int num;

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

void	ft_print_tetriminos(t_tetr *t, int index)
{
	char	**p;
	int		i;

	p = ft_inil_array(t);
	i = 0;
	while (i < index)
	{
		ft_print_tetrimino(t->tmino[i], p, 'A' + i);
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
