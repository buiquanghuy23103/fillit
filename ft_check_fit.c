/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:28:10 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/09 18:05:20 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_fit(int *dst, int *src)
{
	int	scol;

	scol = src[SCOL];
	while (*src)
	{
		if ((*src << scol) & *dst)
			return (0);
		src++;
		dst++;
	}
	return (1);
}
