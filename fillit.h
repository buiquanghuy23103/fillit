/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:27:39 by hbui              #+#    #+#             */
/*   Updated: 2022/01/06 12:35:46 by jpikkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

# define MAXTETRIMINOS 26
# define ISFIT 19
# define HEIGHT 18
# define SIZE 17
# define SROW 16

typedef struct s_tetr
{
	int	tmino[26][20];
	int	tcount;
}	t_tetr;

void	ft_topleft(int *tetrimino);
void	ft_top(int tetrimino[]);
void	ft_left(int *tetrimino);
int		ft_right(int *tetrimino);
int		ft_down(int *tetrimino);
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

#endif
