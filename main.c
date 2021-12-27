/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:26:25 by hbui              #+#    #+#             */
/*   Updated: 2021/12/27 08:51:00 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_handle_error(void)
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
			ft_handle_error();
		height++;
		a = 0;
		while (line[a])
		{
			if (a > 4)
				ft_handle_error();
			a++;
		}
		if (a < 4)
			ft_handle_error();
	}
	if (height == 0)
		ft_handle_error();
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage:\t./fillit target_file\n");
		return (0);
	}
	ft_open_close_file(argv[1], O_RDONLY, &ft_handle_error, &ft_solve);
	return (0);
}
