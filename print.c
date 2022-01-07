/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:51:41 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/07 22:18:58 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_tetrimino(int *arr, char **p, int c)
{
	int	j;
	int	i;

	i = 0;
	while (i < arr[HEIGHT])
	{
		j = arr[SIZE] - 1;
		while (j >= 0 && arr[i] > 0)
		{
			if (ft_getbit(arr[i], j))
			{
				p[arr[SROW] + i][arr[SIZE] - 1 - j] = c;
			}
			--j;
		}
		++i;
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
