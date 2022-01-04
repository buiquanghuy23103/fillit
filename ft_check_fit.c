/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:28:10 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/05 00:38:21 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_fit(int *dst, int *src)
{
	int	i;

	i = src[SROW];
	while (i < src[SIZE] && src[i] != 0)
	{
		if (src[i] & dst[i])
			return (0);
		++i;
	}
	return (1);
}
