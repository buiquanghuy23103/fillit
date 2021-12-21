/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huybui <hbui@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:28:49 by huybui            #+#    #+#             */
/*   Updated: 2021/12/21 09:10:21 by huybui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage:\t./fillit target_file\n");
		return (0);
	}
	ft_putstr(argv[1]);
	return (0);
}
