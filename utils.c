/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:46:57 by hbui              #+#    #+#             */
/*   Updated: 2022/02/09 21:46:25 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_rm(int *dst, t_tetr *tetr, int *offbits)
{
	int	i;

	i = 0;
	offbits[tetr->srow] += tetr->b0;
	offbits[tetr->srow + 1] += tetr->b1;
	offbits[tetr->srow + 2] += tetr->b2;
	offbits[tetr->srow + 3] += tetr->b3;
	while (i < tetr->height)
	{
		*dst ^= (tetr->bin[i] << tetr->scol);
		dst++;
		i++;
	}
}

int	ft_add(int *dst, t_tetr *tetr, int *offbits)
{
	int	i;

	i = 0;
	offbits[tetr->srow] -= tetr->b0;
	offbits[tetr->srow + 1] -= tetr->b1;
	offbits[tetr->srow + 2] -= tetr->b2;
	offbits[tetr->srow + 3] -= tetr->b3;
	while (i < tetr->height)
	{
		*dst ^= (tetr->bin[i] << tetr->scol);
		i++;
		dst++;
	}
	return (1);
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
