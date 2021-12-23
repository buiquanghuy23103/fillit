/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:19:27 by hbui              #+#    #+#             */
/*   Updated: 2021/12/20 21:20:04 by huybui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*join;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		join = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
		if (!join)
			return (NULL);
		join[0] = '\0';
		ft_strcat(join, s1);
		ft_strcat(join, s2);
		join[s1_len + s2_len] = '\0';
		return (join);
	}
	return (NULL);
}
