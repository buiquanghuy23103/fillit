/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:22:02 by hbui              #+#    #+#             */
/*   Updated: 2021/12/20 20:33:10 by huybui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dup;

	if (!s)
		return (NULL);
	dup = ft_strdup(s);
	if (!dup)
		return (NULL);
	if (!f)
		return (dup);
	i = 0;
	while (s[i])
	{
		dup[i] = f(i, s[i]);
		i++;
	}
	return (dup);
}
