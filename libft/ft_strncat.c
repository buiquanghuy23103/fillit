/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:18:05 by hbui              #+#    #+#             */
/*   Updated: 2021/12/07 22:27:46 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	k;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (n >= s2_len)
		k = s2_len;
	else
		k = n;
	ft_memmove(s1 + s1_len, s2, k);
	s1[s1_len + k] = '\0';
	return (s1);
}
