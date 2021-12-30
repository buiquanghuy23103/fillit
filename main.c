/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:26:25 by hbui              #+#    #+#             */
/*   Updated: 2021/12/30 11:49:04 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void	ft_read_line(char *line, int *a, int *blocks)
{
	*a = -1;
	while (line[++(*a)])
	{
		if (line[*a] == '#')
			(*blocks)++;
		else if (line[*a] == '.')
			;
		else
			ft_error();
	}
}

void	ft_solve(int fd)
{
	char	*line;
	int		a;
	int		height;
	int		blocks;

	height = 0;
	a = 4;
	blocks = 0;
	while (a == 4 && ft_set(&a, get_next_line(fd, &line)) != -1
		&& ((line && line[0]) || height == 4))
	{
		if (a == 0)
			return ;
		if (!ft_set(&height, height * !!line[0] + !!line[0]) && ft_set(&a, 4))
			continue ;
		ft_read_line(line, &a, &blocks);
		if (height == 4 && (blocks != 4 || ft_set(&blocks, 0)))
			ft_error();
	}
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
