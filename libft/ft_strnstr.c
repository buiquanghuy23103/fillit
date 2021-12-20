/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:32:37 by hbui              #+#    #+#             */
/*   Updated: 2021/12/07 22:28:40 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	haystack_len;
	size_t	needle_len;

	i = 0;
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	if (needle_len <= len)
	{
		while (haystack[i] && i <= len - needle_len)
		{
			if (haystack[i] == needle[0]
				&& ft_strnequ(haystack + i, needle, needle_len))
				return ((char *) haystack + i);
			i++;
		}
	}
	return (NULL);
}
