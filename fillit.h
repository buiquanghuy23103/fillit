/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:27:39 by hbui              #+#    #+#             */
/*   Updated: 2022/02/17 06:40:30 by hbui             ###   ########.fr       */
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
	int			bin[5];
	int			width;
	int			height;
	int			srow;
	int			erow;
	int			scol;
	int			ecol;
}	t_tetr;

void	topleft(t_tetr *tetrimino);
void	topleft_scol(t_tetr *tetrimino);
void	left_scol(t_tetr *tetrimino);
void	error(void);
void	print(t_tetr *t, int tcount, int size);
void	setup(int fd, t_tetr *storage, int *count);
int		solve(t_tetr *storage, int count);
void	increment_size(t_tetr *storage);
void	set_storage(t_tetr *storage, int *tmp);

#endif
