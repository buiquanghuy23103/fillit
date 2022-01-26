/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:42:27 by hbui              #+#    #+#             */
/*   Updated: 2022/01/26 21:28:12 by hbui             ###   ########.fr       */
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

static void	ft_check_and_add_info(t_tetr *s, uint16_t value)
{
	int	i;

	i = 0;
	while (value && !(value % 2))
		value >>= 1;
	while (i < VALID_SIZE)
	{
		if (value == g_valid[i][0])
		{
			s->tmino[s->tcount][HEIGHT] = g_valid[i][1];
			s->tmino[s->tcount][WIDTH] = g_valid[i][2];
			s->tmino[s->tcount][B0] = g_valid[i][3];
			s->tmino[s->tcount][B1] = g_valid[i][4];
			s->tmino[s->tcount][B2] = g_valid[i][5];
			s->tmino[s->tcount][B3] = g_valid[i][6];
			s->tmino[s->tcount][MAXB] = g_valid[i][7];
			s->tmino[s->tcount][MAXBIND] = g_valid[i][8];
			return ;
		}
		++i;
	}
	ft_error();
}

static void	ft_convert2binary(t_tetr *s, int *tmp)
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
			s->tmino[s->tcount][i / 4 - srow] |= 1 << (i % 4);
		}
		++i;
	}
	ft_check_and_add_info(s, value);
}

static void	ft_read_elem(char *tmp, t_tetr *s)
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
	ft_convert2binary(s, t);
	s->tcount++;
}

static void	ft_setup_storage(t_tetr *storage, int *offbits)
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

void	ft_setup(int fd, t_tetr *s, int *offbits)
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
		ft_read_elem(tmp, s);
		ret = read(fd, tmp, 21);
		if ((!last && !ret) || (ret && s->tcount == 26))
			ft_error();
	}
	if (!s->tcount || !(!ret && s->tcount > 0))
		ft_error();
	if (s->tcount > 1)
		ft_increment_size(s);
	ft_setup_storage(s, offbits);
}
