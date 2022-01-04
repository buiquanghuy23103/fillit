/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:46:57 by hbui              #+#    #+#             */
/*   Updated: 2022/01/04 15:50:05 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void	ft_inil_tetr(t_tetr	*tetr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 26)
	{
		while (j < 17)
		{
			tetr->tmino[i][j] = 0;
			++j;
		}
		tetr->tmino[i][j] = size;
		j = 0;
		++i;
	}
	tetr->tcount = 0;
}
