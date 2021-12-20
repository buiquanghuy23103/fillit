/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:01:42 by hbui              #+#    #+#             */
/*   Updated: 2021/12/08 20:28:52 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int					i;
	unsigned char		*str_dst;
	const unsigned char	*str_src;

	if (!dst && !src)
		return (NULL);
	if (((unsigned long) dst) < ((unsigned long) src))
		return (ft_memcpy(dst, src, len));
	else
	{
		i = len - 1;
		str_dst = (unsigned char *) dst;
		str_src = (const unsigned char *) src;
		while (i >= 0)
		{
			str_dst[i] = str_src[i];
			i--;
		}
	}
	return (dst);
}
