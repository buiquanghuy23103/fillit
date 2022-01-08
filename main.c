/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:57:53 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/08 03:29:33 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_tetr	storage[1];
	int		solution[16];
	int		i;

	i = 0;
	ft_bzero(solution, sizeof(solution));
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
	while (i < storage->tcount)
	{

		ft_topleft(storage->tmino[i]);
		++i;
	}
	ft_solve(solution, storage);
	ft_print_tetriminos(storage, storage->tcount);
	/*ft_putstr("SIZE ");
	ft_putnbr(storage->tmino[0][SIZE]);
	ft_putchar('\n');
	ft_putstr("SROW ");
	ft_putnbr(storage->tmino[0][SROW]);
	ft_putchar('\n');
	ft_putstr("HEIGHT ");
	ft_putnbr(storage->tmino[0][HEIGHT]);
	ft_putchar('\n');
	ft_putstr("WIDTH ");
	ft_putnbr(storage->tmino[0][WIDTH]);
	ft_putchar('\n');*/
	return (0);
}
