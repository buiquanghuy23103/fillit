/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:26:25 by hbui              #+#    #+#             */
/*   Updated: 2021/12/29 19:09:39 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void	ft_solve(int fd)
{
	char	*line;
	int		a;
	int		height;

	height = 0;
	while (ft_set(&a, get_next_line(fd, &line)))
	{
		if (a == -1)
			ft_error();
		height++;
		a = 0;
		while (line[a])
		{
			if (a > 4)
				ft_error();
			a++;
		}
		if (a < 4)
			ft_error();
	}
	if (height == 0)
		ft_error();
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage:\t./fillit target_file\n");
		return (0);
	}
	ft_open_close_file(argv[1], O_RDONLY, &ft_error, &ft_solve);
	return (0);
}
