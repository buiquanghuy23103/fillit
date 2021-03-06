/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:18:05 by hbui              #+#    #+#             */
/*   Updated: 2022/01/05 14:05:26 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_strlen;
	size_t	src_strlen;

	dst_strlen = ft_strlen(dst);
	src_strlen = ft_strlen(src);
	if (dstsize > dst_strlen)
	{
		ft_strncat(dst, src, dstsize - dst_strlen - 1);
		return (dst_strlen + src_strlen);
	}
	return (dstsize + src_strlen);
}
