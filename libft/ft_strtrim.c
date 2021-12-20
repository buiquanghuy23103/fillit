/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:27:45 by hbui              #+#    #+#             */
/*   Updated: 2021/12/05 21:51:41 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char	*ft_strtrim(char const *s)
{
	int	start;
	int	end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] && ft_iswhitespace(s[start]))
		start++;
	if (end >= 0)
	{
		while (s[end] && ft_iswhitespace(s[end]))
			end--;
	}
	if (start >= end)
		return (ft_strdup(""));
	return (ft_strsub(s, start, end - start + 1));
}
