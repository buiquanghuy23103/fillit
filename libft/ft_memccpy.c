/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:26:15 by hbui              #+#    #+#             */
/*   Updated: 2021/12/21 22:43:49 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*str_dst;
	const unsigned char	*str_src;
	unsigned char		unsigned_c;

	i = 0;
	str_dst = (unsigned char *) dst;
	str_src = (const unsigned char *) src;
	unsigned_c = (unsigned char) c;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		if (str_src[i] == unsigned_c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
