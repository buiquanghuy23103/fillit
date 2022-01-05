/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:22:48 by hbui              #+#    #+#             */
/*   Updated: 2022/01/05 14:05:13 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*str;
	size_t			i;

	if (len > 0)
	{
		ch = (unsigned char) c;
		i = 0;
		str = (unsigned char *) b;
		while (i < len)
		{
			str[i] = ch;
			i++;
		}
	}
	return (b);
}
