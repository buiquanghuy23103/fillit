/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:51:21 by hbui              #+#    #+#             */
/*   Updated: 2022/01/04 22:27:13 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_top(int *tetrimino)
{
	int	i;

	i = tetrimino[SROW];
	if (i == 0)
		return ;
	ft_memmove(tetrimino, tetrimino + i, sizeof(int) * (16 - i));
	tetrimino[SROW] = 0;
}
