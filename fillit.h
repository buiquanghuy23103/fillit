/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:27:39 by hbui              #+#    #+#             */
/*   Updated: 2022/01/28 13:26:24 by hbui             ###   ########.fr       */
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

/*
* Index	Name	Value
* 0		-		0000
* 1		-		0111
* 2		-		0010
* 3		-		0000
* 4		-		NULL
* 5		WIDTH	3
* 6		SROW	1
* 7		SIZE	4 (size of the square)
* 8		HEIGHT	2
* 9		SCOL	1
* 10	ECOL	3
* 11	EROW	2
* 12	B0		0
* 13	B1		3
* 14	B2		1
* 15	B3		0
* 16	MAXB	3
* 17	MAXBIND	1
*/

typedef struct s_tetr
{
	int	tmino[MAXTETRIMINOS][T_SIZE];
	int	tcount;
}	t_tetr;

void	ft_topleft(int *tetrimino);
void	ft_topleft_scol(int *tetrimino);
void	ft_left_scol(int *tetrimino);
void	ft_error(void);
void	ft_init_storage(t_tetr	*tetr);
void	ft_print_result(t_tetr *t, int index);
void	ft_setup(int fd, t_tetr *storage, int *offbits);
int		ft_check_fit(int *dst, int *src);
void	ft_rm(int *dst, int *src, int *offbits);
void	ft_solve(int *solution, t_tetr *storage, int *offbits, int *full);
int		ft_add(int *dst, int *src, int *offbits);
void	ft_increment_size(t_tetr *storage);
void	ft_set_storage(t_tetr *storage, int *tmp);
int		ft_reset(t_tetr *storage, int *offbits, int *full);

#endif
