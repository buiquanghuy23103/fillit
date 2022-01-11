/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:42:27 by hbui              #+#    #+#             */
/*   Updated: 2022/01/12 00:53:52 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdint.h>

static const uint16_t	g_valid[19][9] =
				{{0b0000000110010001, 3, 2, 2, 1, 1, 0, 2, 0},
				{0b0000000001110001, 2, 3, 3, 1, 0, 0, 3, 0},
				{0b0000000100010011, 3, 2, 1, 1, 2, 0, 2, 2},
				{0b0000000001000111, 2, 3, 1, 3, 0, 0, 3, 1},

				{0b0000001100010001, 3, 2, 2, 1, 1, 0, 2, 0},
				{0b0000000000010111, 2, 3, 1, 3, 0, 0, 3, 1},
				{0b0000001000100011, 3, 2, 1, 1, 2, 0, 2, 2},
				{0b0000000000011101, 2, 3, 3, 1, 0, 0, 3, 0},

				{0b0000000000110011, 2, 2, 2, 2, 0, 0, 2, 0},

				{0b0000000000001111, 1, 4, 4, 0, 0, 0, 4, 0},
				{0b0001000100010001, 4, 1, 1, 1, 1, 1, 1, 0},

				{0b0000000100011001, 3, 2, 1, 2, 1, 0, 2, 1},
				{0b0000000000111001, 2, 3, 3, 1, 0, 0, 3, 0},
				{0b0000000100110001, 3, 2, 1, 2, 1, 0, 2, 1},
				{0b0000000000100111, 2, 3, 1, 3, 0, 0, 3, 1},

				{0b0000000001100011, 2, 3, 2, 2, 0, 0, 2, 0},
				{0b0000000010011001, 3, 2, 1, 2, 1, 0, 2, 1},
				{0b0000000000011011, 2, 3, 2, 2, 0, 0, 2, 0},
				{0b0000001000110001, 3, 2, 1, 2, 1, 0, 2, 1}};

void	ft_check_input(t_tetr *storage, uint16_t value)
{
	int i;

	i = 0;
	while (!(value % 2))
		value >>= 1;
	while (i < VALID_SIZE)
	{
		if (value == g_valid[i][0])
		{
			storage->tmino[storage->tcount][HEIGHT] = g_valid[i][1];
			storage->tmino[storage->tcount][WIDTH] = g_valid[i][2];
			storage->tmino[storage->tcount][BITS0] = g_valid[i][3];
			storage->tmino[storage->tcount][BITS1] = g_valid[i][4];
			storage->tmino[storage->tcount][BITS2] = g_valid[i][5];
			storage->tmino[storage->tcount][BITS3] = g_valid[i][6];
			storage->tmino[storage->tcount][MAXBITS] = g_valid[i][7];
			storage->tmino[storage->tcount][MAXBIND] = g_valid[i][8];
			return ;
		}
		++i;
	}
	ft_error();
}

void	ft_set_storage(t_tetr *storage, int *tmp)
{
	int			i;
	uint16_t	value;
	int			srow;

	value = 0;
	i = 0;
	srow = -1;
	while (i < 16)
	{
		if (tmp[i])
		{
			value |= 1 << (15 - i);
			if (srow == -1)
				srow = i / 4;
			storage->tmino[storage->tcount][i / 4 - srow] |= 1 << (i % 4);
		}
		++i;
	}
	ft_check_input(storage, value);
}

static void	ft_check_elems(char *tmp, t_tetr *storage)
{
	int	i;
	int	j;
	int	t[16];

	i = -1;
	j = 0;
	ft_bzero(t, sizeof(t));
	i = -1;
	while (tmp[++i])
	{
		if (!((i + 1) % 5) || !((i + 1) % 21))
		{
			if (tmp[i] != '\n')
				ft_error();
			continue ;
		}
		if (tmp[i] == '#')
			t[j] = 1;
		else if (tmp[i] != '.')
			ft_error();
		j++;
	}
	ft_set_storage(storage, t);
	storage->tcount++;
}

void	ft_set_minsize(t_tetr *storage)
{
	int	i;
	int	j;
	int	*tetr0;

	tetr0 = storage->tmino[0];
	i = tetr0[SIZE] + 1;
	j = 0;
	while (storage->tcount * 4 > i * i
			|| i < tetr0[HEIGHT]
			|| i < tetr0[WIDTH])
	{
		++i;
	}
	while (j < MAXTETRIMINOS)
	{
		storage->tmino[j][SIZE] = i;
		++j;
	}
}

void	ft_validate(int fd, t_tetr *storage)
{
	char	tmp[22];
	int		ret;
	int		last;

	last = 0;
	ret = read(fd, tmp, 21);
	tmp[21] = '\0';
	while (ret == 21 || ret == 20)
	{
		if (ret == 20)
		{
			last = 1;
			tmp[20] = '\n';
		}
		ft_check_elems(tmp, storage);
		ret = read(fd, tmp, 21);
		if ((!last && !ret) || (ret && storage->tcount == 26))
			ft_error();
	}
	if (!storage->tcount || !(!ret && storage->tcount > 0))
		ft_error();
	if (storage->tcount > 1 || storage->tmino[0][WIDTH] > 2 || storage->tmino[0][HEIGHT] > 2)
		ft_set_minsize(storage);
}
