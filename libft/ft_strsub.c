/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:24:59 by hbui              #+#    #+#             */
/*   Updated: 2021/12/07 22:29:13 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (s)
	{
		sub = ft_strnew(len);
		if (!sub)
			return (NULL);
		while (i < len)
		{
			sub[i] = s[start + i];
			i++;
		}
		return (sub);
	}
	return (NULL);
}
