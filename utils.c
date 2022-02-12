/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:46:57 by hbui              #+#    #+#             */
/*   Updated: 2022/02/12 23:05:02 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	manage_board(uint16_t *board, t_tetr *tetr, int *offbits, int action)
{
	int	i;

	i = 0;
	offbits[tetr->srow] -= tetr->b0 * action;
	offbits[tetr->srow + 1] -= tetr->b1 * action;
	offbits[tetr->srow + 2] -= tetr->b2 * action;
	offbits[tetr->srow + 3] -= tetr->b3 * action;
	while (i < tetr->height)
	{
		*board ^= (tetr->bin[i] << tetr->scol);
		i++;
		board++;
	}
	return (1);
}

void	ft_rm(uint16_t *board, t_tetr *tetr, int *offbits)
{
	manage_board(board, tetr, offbits, -1);
}

void	ft_add(uint16_t *board, t_tetr *tetr, int *offbits)
{
	manage_board(board, tetr, offbits, 1);
}

int	ft_reset(t_tetr *tetr0, int *offbits, int *full, int *size)
{
	int	i;

	i = 0;
	tetr0->srow = 0;
	tetr0->erow = tetr0->height;
	tetr0->scol = 0;
	tetr0->ecol = tetr0->width;
	(*size)++;
	*full = ft_setbit(0, *size) - 1;
	while (i < *size)
	{
		offbits[i] = *size;
		i++;
	}
	return (1);
}
