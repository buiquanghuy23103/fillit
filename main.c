/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:57:53 by jpikkuma          #+#    #+#             */
/*   Updated: 2022/01/03 18:06:48 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdint.h>

static const uint16_t	valid[112] = {0b1100100010000000, 0b0110010001000000, 0b0011001000100000,
							0b0000110010001000, 0b0000011001000100, 0b0000001100100010,
							0b1110001000000000, 0b0111000100000000, 0b0000111000100000,
							0b0000011100010000, 0b0000000011100010, 0b0000000001110001,
							0b0100010011000000, 0b0010001001100000, 0b0001000100110000,
							0b0000010001001100, 0b0000001000100110, 0b0000000100010011,
							0b1000111000000000, 0b0100011100000000, 0b0000100011100000,
							0b0000010001110000, 0b0000000010001110, 0b0000000001000111,
							0b1100010001000000, 0b0110001000100000, 0b0011000100010000,
							0b0000110001000100, 0b0000011000100010, 0b0000001100010001,
							0b0010111000000000, 0b0001011100000000, 0b0000001011100000,
							0b0000000101110000, 0b0000000000101110, 0b0000000000010111,
							0b1000100011000000, 0b0100010001100000, 0b0010001000110000,
							0b0000100010001100, 0b0000010001000110, 0b0000001000100011,
							0b1110001000000000, 0b0111000100000000, 0b0000111000100000,
							0b0000011100010000, 0b0000000011100010, 0b0000000001110001,
							0b1100110000000000, 0b0110011000000000, 0b0011001100000000,
							0b0000110011000000, 0b0000011001100000, 0b0000000011001100,
							0b0000000001100110, 0b0000000000110011, 0b1111000000000000,
							0b0000111100000000, 0b0000000011110000, 0b0000000000001111,
							0b1000100010001000, 0b0100010001000100, 0b0010001000100010,
							0b0001000100010001, 0b1000110010000000, 0b0100011001000000,
							0b0010001100100000, 0b0000100011001000, 0b0000010001100100,
							0b0000001000110010, 0b1110010000000000, 0b0111001000000000,
							0b0000111001000000, 0b0000011100100000, 0b0000000011100100,
							0b0000000001110010, 0b0100110001000000, 0b0010011000100000,
							0b0001001100010000, 0b0000010011000100, 0b0000001001100010,
							0b0000000100110001, 0b0100111000000000, 0b0010011100000000,
							0b0000010011100000, 0b0000001001110000, 0b0000000001001110,
							0b0000000000100111, 0b1100011000000000, 0b0110001100000000,
							0b0000110001100000, 0b0000011000110000, 0b0000000011000110,
							0b0000000001100011, 0b0100110010000000, 0b0010011001000000,
							0b0001001100100000, 0b0000010011001000, 0b0000001001100100,
							0b0000000100110010, 0b0110110000000000, 0b0011011000000000,
							0b0000011011000000, 0b0000001101100000, 0b0000000001101100,
							0b0000000000110110, 0b1000110001000000, 0b0100011000100000,
							0b0010001100010000, 0b0000100011000100, 0b0000010001100010,
							0b0000001000110001};

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void	ft_inil_tetr(t_tetr	*tetr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 26)
	{
		while (j < 4)
		{
			tetr->tmino[i][j] = 0;
			++j;
		}
		j = 0;
		++i;
	}
	tetr->tcount = 0;
}

int	ft_set_storage(t_tetr *storage, int *tmp, int tc)
{
	int			i;
	int			proper;
	uint16_t	value;

	value = 0;
	proper = 0;
	i = 0;
	while (i < 16)
	{
		if (tmp[i])
		{
			value |= 1 << i;
			storage->tmino[tc][i / 4] |= 1 << (3 - (i % 4));
		}
		++i;
	}
	i = 0;
	while (i < 112)
	{
		if (value == valid[i])
			proper = 1;
		++i;
	}
	if (!proper)
		return (0);
	printf("Tetrimino %d: %d %d %d %d\n", tc, storage->tmino[tc][0], storage->tmino[tc][1], storage->tmino[tc][2], storage->tmino[tc][3]);
	return (1);
}

void	ft_init_t(int *t)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		t[i] = 0;
		++i;
	}
}

int	ft_validate(int fd, t_tetr *storage)
{
	char	tmp[22];
	int		i;
	int		j;
	int		ret;
	int		tc;
	int		t[16];

	tc = 0;
	ret = read(fd, tmp, 21);
	tmp[21] = '\0';
	while (ret == 21)
	{
		j = 0;
		i = -1;
		ft_init_t(t);
		while (tmp[++i])
		{
			if (!((i + 1) % 5) || !((i + 1) % 21))
			{
				if (tmp[i] != '\n')
					return (0);
				continue ;
			}
			if (tmp[i] == '#')
				t[j] = 1;
			else if (tmp[i] != '.')
				return (0);
			j++;
		}
		ret = read(fd, tmp, 21);
		if (!(ft_set_storage(storage, t, tc++)))
			return (0);
	}
	return(!ret && tc > 0);
}

int	main(int argc, char **argv)
{
	int	fd;
	t_tetr	storage[1];

	if (argc != 2)
	{
		ft_putstr("usage:\t./fillit target_file\n");
		return (0);
	}
	ft_inil_tetr(storage);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	else
		if (!ft_validate(fd, storage))
			ft_error();
	ft_putstr("Valid input\n");
	return (0);
}