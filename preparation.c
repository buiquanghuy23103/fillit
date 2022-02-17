/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:42:27 by hbui              #+#    #+#             */
/*   Updated: 2022/02/17 07:02:38 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static const uint16_t	g_valid[VALID_SIZE][9] = {
{0b0000000110010001, 3, 2, 2, 1, 1, 0, 2, 0},
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

static uint64_t	to_bin64(int *bin)
{
	int			i;
	uint16_t	bin16[4];
	uint64_t	bin64;

	i = -1;
	while (++i < 4)
		bin16[i] = (uint16_t)bin[i];
	bin64 = *(uint64_t *)bin16;
	while (1)
	{
		if (!ft_getbit(bin64, 48)
			&& !ft_getbit(bin64, 32)
			&& !ft_getbit(bin64, 16)
			&& !ft_getbit(bin64, 0))
			bin64 >>= 1;
		else
			break ;
	}
	return (bin64);
}

static void	build_bin_array(t_tetr *tetr, uint16_t bin16)
{
	int	i;
	int	srow;

	i = 0;
	srow = -1;
	ft_bzero(tetr->bin, sizeof(tetr->bin));
	while (i < 16)
	{
		if (ft_getbit(bin16, 15 - i))
		{
			if (srow == -1)
				srow = i / 4;
			tetr->bin[i / 4 - srow] |= 1 << (i % 4);
		}
		++i;
	}
}

static void	build_tetr(t_tetr *tetr, uint16_t value)
{
	int	i;

	i = 0;
	if (!value)
		error();
	build_bin_array(tetr, value);
	tetr->bin64 = to_bin64(tetr->bin);
	while (!(value % 2))
		value >>= 1;
	while (i < VALID_SIZE)
	{
		if (value == g_valid[i][0])
		{
			tetr->height = g_valid[i][1];
			tetr->width = g_valid[i][2];
			topleft(tetr);
			return ;
		}
		++i;
	}
	error();
}

static uint16_t	to_bin16(char *tmp)
{
	int			i;
	int			row;
	uint16_t	bin;

	i = -1;
	row = 0;
	bin = 0;
	while (tmp[++i])
	{
		if (!((i + 1) % 5) || !((i + 1) % 21))
		{
			if (tmp[i] != '\n')
				error();
			row++;
			continue ;
		}
		if (tmp[i] == '#')
			bin = ft_setbit(bin, 15 - (i - row));
		else if (tmp[i] != '.')
			error();
	}
	return (bin);
}

void	setup(int fd, t_tetr *s, int *count)
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
		build_tetr(s + *count, to_bin16(tmp));
		(*count)++;
		ret = read(fd, tmp, 21);
		if ((!last && !ret) || (ret && *count == 26))
			error();
	}
	if (!(*count) || !(!ret && *count > 0))
		error();
}
