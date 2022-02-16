/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:42:27 by hbui              #+#    #+#             */
/*   Updated: 2022/02/16 21:17:02 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static const	uint16_t
	g_valid[VALID_SIZE][9] = {
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

// static void	putbin64(const uint64_t bin64)
// {
// 	int	i;

// 	i = 64;
// 	while(--i >= 0)
// 	{
// 		if (ft_getbit(bin64, i))
// 			ft_putchar('1');
// 		else
// 			ft_putchar('0');
// 		if (i % 16)
// 			ft_putchar(' ');
// 		else
// 			ft_putchar('\n');
// 	}
// 	ft_putchar('\n');
// }

static uint64_t	left(uint64_t bin64)
{
	while (1)
	{
		if (!ft_getbit(bin64, 48)
			&& !ft_getbit(bin64, 32)
			&& !ft_getbit(bin64, 16)
			&& !ft_getbit(bin64, 0))
			bin64 >>= 1;
		else
			return (bin64);
	}
	return (bin64);
}

static uint64_t	to_bin64(int *bin)
{
	int	i;
	uint16_t	bin16[4];
	uint64_t	bin64;

	i = -1;
	while (++i < 4)
		bin16[i] = (uint16_t)bin[i];
	bin64 = *(uint64_t*)bin16;
	bin64 = left(bin64);
	// putbin64(bin64);
	return (bin64);
}

static void	set_tetr_bin(t_tetr *tetr, uint16_t bin)
{
	int			i;
	int			srow;

	i = 0;
	srow = -1;
	while (i < 16)
	{
		if (ft_getbit(bin, 15 - i))
		{
			if (srow == -1)
				srow = i / 4;
			tetr->bin[i / 4 - srow] |= 1 << (i % 4);
		}
		++i;
	}
	tetr->bin[4] = 0;
}

static void	ft_check_and_add_info(t_tetr *tetr, uint16_t value)
{
	int	i;

	i = 0;
	if (!value)
		ft_error();
	set_tetr_bin(tetr, value);
	tetr->bin64 = to_bin64(tetr->bin);
	while (!(value % 2))
		value >>= 1;
	while (i < VALID_SIZE)
	{
		if (value == g_valid[i][0])
		{
			tetr->height = g_valid[i][1];
			tetr->width = g_valid[i][2];
			tetr->maxbind = g_valid[i][8];
			ft_topleft(tetr);
			return ;
		}
		++i;
	}
	ft_error();
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
				ft_error();
			row++;
			continue ;
		}
		if (tmp[i] == '#')
			bin = ft_setbit(bin, 15 - (i - row));
		else if (tmp[i] != '.')
			ft_error();
	}
	return (bin);
}

void	ft_setup(int fd, t_tetr *s, int *count)
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
		ft_check_and_add_info(s + *count, to_bin16(tmp));
		(*count)++;
		ret = read(fd, tmp, 21);
		if ((!last && !ret) || (ret && *count == 26))
			ft_error();
	}
	if (!(*count) || !(!ret && *count > 0))
		ft_error();
}
