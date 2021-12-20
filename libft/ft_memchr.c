/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:02:03 by hbui              #+#    #+#             */
/*   Updated: 2021/12/09 12:46:34 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str_s;
	unsigned char		unsigned_c;

	i = 0;
	str_s = (const unsigned char *) s;
	unsigned_c = (unsigned char) c;
	while (i < n)
	{
		if (str_s[i] == unsigned_c)
			return ((void *)(str_s + i));
		i++;
	}
	return (NULL);
}
