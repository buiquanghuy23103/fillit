/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:57:53 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/26 21:27:28 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void	ft_topleft(int *tetrimino)
{
	ft_top(tetrimino);
	ft_left(tetrimino);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_tetr	storage[1];
	int		solution[16];
	int		offbits[17];
	int		full;

	ft_bzero(solution, sizeof(solution));
	ft_bzero(offbits, sizeof(offbits));
	if (argc != 2)
	{
		ft_putstr("usage:\t./fillit target_file\n");
		return (0);
	}
	ft_inil_tetr(storage, 2);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	ft_setup(fd, storage, offbits);
	full = ft_setbit(0, storage->tmino[0][SIZE]) - 1;
	ft_solve(solution, storage, offbits, &full);
	ft_print_result(storage, storage->tcount);
	return (0);
}
