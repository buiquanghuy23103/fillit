/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_topleft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:08:28 by hbui              #+#    #+#             */
/*   Updated: 2022/01/04 15:35:10 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_topleft(int tetrimino[16], const unsigned int size)
{
	ft_top(tetrimino);
	ft_left(tetrimino, size);
}
