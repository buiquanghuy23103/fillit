/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:27:39 by hbui              #+#    #+#             */
/*   Updated: 2022/01/12 13:45:13 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

# define MAXTETRIMINOS 26
# define T_SIZE 18
# define INFO_SIZE 6
# define VALID_SIZE 19
# define MAXBIND 17
# define MAXB 16
# define B3 15
# define B2 14
# define B1 13
# define B0 12
# define EROW 11
# define ECOL 10
# define SCOL 9
# define HEIGHT 8
# define SIZE 7
# define SROW 6
# define WIDTH 5

typedef struct s_tetr
{
	int	tmino[MAXTETRIMINOS][T_SIZE];
	int	tcount;
}	t_tetr;

void	ft_topleft(int *tetrimino);
void	ft_topleft_incr(int *tetrimino);
void	ft_topleft_scol(int *tetrimino);
void	ft_top(int tetrimino[]);
void	ft_left(int *tetrimino);
void	ft_left_incr(int *tetrimino);
void	ft_left_scol(int *tetrimino);
void	ft_error(void);
void	ft_inil_tetr(t_tetr	*tetr, int size);
char	**ft_inil_array(t_tetr *t);
void	ft_print_tetriminos(t_tetr *t, int index);
void	ft_validate(int fd, t_tetr *storage);
int		ft_check_fit(int *dst, int *src);
int		ft_check_fit_tmp(int *dst, int *src, int *offbits, int full);
void	ft_rm(int *dst, int *src, int *offbits);
void	ft_solve(int *solution, t_tetr *storage, int *offbits, int *full);
int		ft_add(int *dst, int *src, int *offbits);
void	ft_set_minsize(t_tetr *storage);
void	ft_set_storage(t_tetr *storage, int *tmp);
int		ft_reset(t_tetr *storage, int *offbits, int *full);

#endif
