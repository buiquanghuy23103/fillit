/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:08:57 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/02/17 11:11:45 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	init_size(t_tetr *s, int count)
{
	int	size;
	int	i;

	size = 2;
	i = 0;
	while (size * size < count * 4)
		size++;
	while (i < count)
	{
		if (s[i].width > size || s[i].height > size)
		{
			size++;
			continue ;
		}
		i++;
	}
	return (size);
}

static int	reset(t_tetr *tetr0, int *size)
{
	topleft_scol(tetr0);
	(*size)++;
	return (1);
}

static int	move(t_tetr *tet, int size)
{
	if (tet->ecol == size)
	{
		if (tet->erow == size)
			return (0);
		left_scol(tet);
		++(tet->srow);
		++(tet->erow);
		return (1);
	}
	++(tet->scol);
	++(tet->ecol);
	return (1);
}

int	solve(t_tetr *s, int count)
{
	int			i;
	int			size;
	uint16_t	sol[16];

	i = 0;
	size = init_size(s, count);
	ft_bzero(sol, sizeof(sol));
	while (i < count)
	{
		if (!(*(uint64_t *)(sol + s[i].srow) & (s[i].bin64 << s[i].scol)))
		{
			*(uint64_t *)(sol + s[i].srow) ^= (s[i].bin64 << s[i].scol);
			++i;
			continue ;
		}
		while (!move(s + i, size) && (i != 0 || !reset(s + 0, &size)))
		{
			topleft_scol(s + i--);
			*(uint64_t *)(sol + s[i].srow) ^= (s[i].bin64 << s[i].scol);
		}
	}
	return (size);
}
