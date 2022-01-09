/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/09 17:47:31 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solve(int *solution, t_tetr *storage)
{
	int	i;
	int	offbits[16];
	int	full;

	i = 0;
	full = ft_setbit(0, storage->tmino[i][SIZE]) - 1;
	ft_bzero(offbits, sizeof(offbits));
	while (i < storage->tmino[i][SIZE])
	{
		offbits[i] = storage->tmino[i][SIZE];
		++i;
	}
	i = 0;
	while (i < storage->tcount)
	{
				// ft_print_tetriminos(storage, i + 1);ft_putchar('\n');
		if (ft_check_fit(solution + storage->tmino[i][SROW], storage->tmino[i]))
		{
			ft_place_piece(solution + storage->tmino[i][SROW], storage->tmino[i]);
			offbits[storage->tmino[i][SROW]] -= storage->tmino[i][BITS0];
			offbits[storage->tmino[i][SROW] + 1] -= storage->tmino[i][BITS1];
			offbits[storage->tmino[i][SROW] + 2] -= storage->tmino[i][BITS2];
			offbits[storage->tmino[i][SROW] + 3] -= storage->tmino[i][BITS3];
			++i;
			continue ;
		}
		while ((!ft_right(storage->tmino[i]) && !ft_down(solution, storage->tmino[i], offbits, full)))
		{
			if (i == 0)
			{
				ft_topleft_scol(storage->tmino[i]);
				ft_set_minsize(storage);
				full = ft_setbit(0, storage->tmino[i][SIZE]) - 1;
				while (i < storage->tmino[i][SIZE])
				{
					offbits[i] = storage->tmino[i][SIZE];
					i++;
				}
				i = 0;
				while (i < storage->tcount)
					ft_topleft_incr(storage->tmino[i++]);
				i = 0;
				break ;
			}
			else
			{
				ft_topleft_scol(storage->tmino[i]);
				ft_remove_piece(solution + storage->tmino[i - 1][SROW], storage->tmino[i - 1]);
				offbits[storage->tmino[i - 1][SROW]] += storage->tmino[i - 1][BITS0];
				offbits[storage->tmino[i - 1][SROW] + 1] += storage->tmino[i - 1][BITS1];
				offbits[storage->tmino[i - 1][SROW] + 2] += storage->tmino[i - 1][BITS2];
				offbits[storage->tmino[i - 1][SROW] + 3] += storage->tmino[i - 1][BITS3];
				--i;
			}
		}
	}
}
