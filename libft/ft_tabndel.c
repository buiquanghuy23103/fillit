/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabndel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:20:50 by hbui              #+#    #+#             */
/*   Updated: 2021/12/09 12:07:02 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabndel(void **tab, size_t tab_len)
{
	size_t	i;
	int		**itab;

	if (tab && *tab && tab_len > 0)
	{
		i = 0;
		itab = (int **) tab;
		while (i < tab_len)
		{
			free(itab[i]);
			i++;
		}
		free(tab);
	}
}
