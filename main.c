/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:57:53 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/02/16 22:12:03 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_tetr	storage[MAXTETRIMINOS + 1];
	int		size;
	int		count;

	size = 0;
	count = 0;
	if (argc != 2)
	{
		ft_putstr("usage:\t./fillit target_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error();
	ft_bzero(storage, sizeof(storage));
	setup(fd, storage, &count);
	size = solve(storage, count);
	print(storage, count, size);
	return (0);
}
