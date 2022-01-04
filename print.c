/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:51:41 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/04 21:05:32 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_tetrimino(int *arr, char **p, int c)
{
	int	i;
	int	j;

	i = 0;
	j = arr[SIZE] - 1;
	while (i < arr[SIZE])
	{
		while (j >= 0)
		{
			if (ft_getbit(arr[i], j))
				p[i][arr[SIZE] - 1 - j] = c;
			--j;
		}
		j = arr[SIZE] - 1;
		++i;
	}
}

void	ft_print_tetriminos(t_tetr *t)
{
	char	**p;
	int		i;

	p = ft_inil_array(t);
	i = 0;
	while (i < t->tcount)
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
