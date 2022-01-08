/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:28:10 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/08 18:29:34 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_fit(int *dst, int *src)
{
	while (*src)
	{
		if (*src & (*dst >> (dst)[SCOL]))
			return (0);
		src++;
		dst++;
	}
	return (1);
}
