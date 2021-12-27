/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:26:25 by hbui              #+#    #+#             */
/*   Updated: 2021/12/27 08:24:42 by hbui             ###   ########.fr       */
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
	int		ret;

	while (ft_set(&ret, get_next_line(fd, &line)))
	{
		if (ret == -1)
			ft_handle_error();
	}
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
