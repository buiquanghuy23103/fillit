/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max1bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:48:43 by hbui              #+#    #+#             */
/*   Updated: 2022/01/12 07:53:32 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max1bits(int x)
{
	int	count;

	count = 0;
	while (x != 0)
	{
		x = (x & (x << 1));
		count++;
	}
	return (count);
}
