/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:26:25 by hbui              #+#    #+#             */
/*   Updated: 2021/12/26 23:08:53 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_error(void)
{
	ft_putstr("error\n");
}

void	ft_solve(int fd)
{
	char	*line;

	get_next_line(fd, &line);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage:\t./fillit target_file\n");
		return (0);
	}
	ft_open_close_file(argv[1], O_RDONLY, &ft_print_error, &ft_solve);
	return (0);
}
