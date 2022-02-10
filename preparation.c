/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:42:27 by hbui              #+#    #+#             */
/*   Updated: 2022/02/10 14:07:36 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdint.h>

static const	uint16_t
	g_valid[19][9] = {{0b0000000110010001, 3, 2, 2, 1, 1, 0, 2, 0},
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
	set_tetr_bin(tetr, value);
	while (value && !(value % 2))
		value >>= 1;
	while (i < VALID_SIZE)
	{
		if (value == g_valid[i][0])
		{
			tetr->height = g_valid[i][1];
			tetr->width = g_valid[i][2];
			tetr->b0 = g_valid[i][3];
			tetr->b1 = g_valid[i][4];
			tetr->b2 = g_valid[i][5];
			tetr->b3 = g_valid[i][6];
			tetr->maxb = g_valid[i][7];
			tetr->maxbind = g_valid[i][8];
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
			bin |= (1 << (15 - (i - row)));
		else if (tmp[i] != '.')
			ft_error();
	}
	return (bin);
}

static void	ft_setup_storage(t_tetr *storage, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_topleft(storage + i);
		++i;
	}
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
	ft_setup_storage(s, *count);
}
