/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:57:53 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/12 12:03:22 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_topleft(int *tetrimino)
{
	ft_top(tetrimino);
	ft_left(tetrimino);
}

void	ft_setup_storage(t_tetr *storage, int *offbits)
{
	int	i;

	i = 0;
	while (i < storage->tcount)
	{
		ft_topleft(storage->tmino[i]);
		++i;
	}
	i = 0;
	while (i < storage->tmino[i][SIZE])
	{
		offbits[i] = storage->tmino[i][SIZE];
		++i;
	}
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
	ft_validate(fd, storage);
	ft_setup_storage(storage, offbits);
	full = ft_setbit(0, storage->tmino[0][SIZE]) - 1;
	ft_solve(solution, storage, offbits, &full);
	ft_print_tetriminos(storage, storage->tcount);
	return (0);
}
