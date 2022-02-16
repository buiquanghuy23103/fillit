/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:46:57 by hbui              #+#    #+#             */
/*   Updated: 2022/02/16 20:07:03 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	manage_board(uint16_t *board, t_tetr *tetr)
{
	int	i;

	i = 0;
	while (i < tetr->height)
	{
		*board ^= (tetr->bin[i] << tetr->scol);
		i++;
		board++;
	}
	return (1);
}

void	ft_rm(uint16_t *board, t_tetr *tetr)
{
	manage_board(board, tetr);
}

void	ft_add(uint16_t *board, t_tetr *tetr)
{
	manage_board(board, tetr);
}

int	ft_reset(t_tetr *tetr0, int *full, int *size)
{
	int	i;

	i = 0;
	tetr0->srow = 0;
	tetr0->erow = tetr0->height;
	tetr0->scol = 0;
	tetr0->ecol = tetr0->width;
	(*size)++;
	*full = ft_setbit(0, *size) - 1;
	return (1);
}
