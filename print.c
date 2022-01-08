/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:51:41 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/08 02:31:48 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_tetrimino(int *arr, char **p, int c)
{
	int	i;
	int	j;
	int k;

	k = 0;
	i = arr[SROW];
	j = arr[SIZE] - 1;
	while (k < arr[HEIGHT])
	{
		while (j >= 0)
		{
			if (ft_getbit(arr[k], j))
				p[i + k][arr[SIZE] - 1 - j] = c;
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
