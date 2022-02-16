/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:27:39 by hbui              #+#    #+#             */
/*   Updated: 2022/02/16 20:34:47 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

# define MAXTETRIMINOS 26
# define VALID_SIZE 19

typedef struct s_tetr
{
	uint64_t	bin64;
	int	bin[5];
	int	width;
	int	height;
	int	srow;
	int	erow;
	int	scol;
	int	ecol;
	int	b0;
	int	b1;
	int	b2;
	int	b3;
	int	maxb;
	int	maxbind;
}	t_tetr;

void	ft_topleft(t_tetr *tetrimino);
void	ft_topleft_scol(t_tetr *tetrimino);
void	ft_left_scol(t_tetr *tetrimino);
void	ft_error(void);
void	ft_print_result(t_tetr *t, int tcount, int size);
void	ft_setup(int fd, t_tetr *storage, int *count);
int		ft_solve(t_tetr *storage, int count);
void	ft_increment_size(t_tetr *storage);
void	ft_set_storage(t_tetr *storage, int *tmp);

#endif
