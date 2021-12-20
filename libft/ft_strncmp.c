/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:42:18 by hbui              #+#    #+#             */
/*   Updated: 2021/12/08 20:32:14 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*u1;
	const unsigned char	*u2;

	i = 0;
	if (n == 0)
		return (0);
	u1 = (const unsigned char *) s1;
	u2 = (const unsigned char *) s2;
	while (i < n - 1 && u1[i] && u1[i] == u2[i])
		i++;
	return (u1[i] - u2[i]);
}
