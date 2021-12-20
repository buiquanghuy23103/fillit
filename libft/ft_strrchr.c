/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:23:12 by hbui              #+#    #+#             */
/*   Updated: 2021/12/03 16:09:48 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (s[i])
	{
		if (s[i] == c)
			k = i;
		i++;
	}
	if (s[i] == c)
		return ((char *) s + i);
	else if (s[k] == c)
		return ((char *) s + k);
	else
		return (NULL);
}
