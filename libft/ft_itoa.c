/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:35:17 by hbui              #+#    #+#             */
/*   Updated: 2021/11/08 22:39:31 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		is_negative;
	int		i;
	int		numlen;

	is_negative = n < 0;
	numlen = ft_numlen(n);
	str = (char *)malloc((numlen + is_negative + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = numlen + is_negative;
	str[i] = '\0';
	i--;
	while (i >= is_negative)
	{
		str[i] = ft_abs(n % 10) + '0';
		n /= 10;
		i--;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
