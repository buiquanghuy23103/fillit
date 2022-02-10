/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:32:06 by hbui              #+#    #+#             */
/*   Updated: 2022/02/10 18:05:36 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t	ft_setbit(const uint64_t num, const unsigned int i)
{
	uint64_t	mask;

	mask = ((uint64_t)1) << i;
	return (num | mask);
}
