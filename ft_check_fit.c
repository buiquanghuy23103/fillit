/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:28:10 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/07 10:54:27 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_fit(int *dst, int *src)
{
	int	i;
	int	square_size;
	int	height;

	i = src[SROW];
	square_size = src[SIZE];
	height = src[HEIGHT];
	if (height > square_size)
		return (0);
	while (i < square_size && src[i] != 0)
	{
		if (src[i] & dst[i])
			return (0);
		++i;
	}
	return (1);
}
