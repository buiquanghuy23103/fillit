/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:27:39 by hbui              #+#    #+#             */
/*   Updated: 2022/01/09 16:07:56 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

# define MAXTETRIMINOS 26
# define T_SIZE 16
# define INFO_SIZE 6
# define VALID_SIZE 19
# define BITS3 15
# define BITS2 14
# define BITS1 13
# define BITS0 12
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
int		ft_right(int *tetrimino);
int		ft_down(int *solution, int *tetrimino, int *offbits, int full);
void	ft_error(void);
void	ft_inil_tetr(t_tetr	*tetr, int size);
char	**ft_inil_array(t_tetr *t);
void	ft_print_tetriminos(t_tetr *t, int index);
void	ft_validate(int fd, t_tetr *storage);
int		ft_check_fit(int *dst, int *src);
void	ft_remove_piece(int *dst, int *src);
void	ft_solve(int *solution, t_tetr *storage);
void	ft_place_piece(int *dst, int *src);
void	ft_set_minsize(t_tetr *storage);
void	ft_set_storage(t_tetr *storage, int *tmp);

#endif
