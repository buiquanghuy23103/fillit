/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:27:39 by hbui              #+#    #+#             */
/*   Updated: 2022/01/04 15:55:08 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

# define SIZE 17
# define SROW 16

typedef struct s_tetr
{
	int	tmino[26][18];
	int	tcount;
}	t_tetr;

void	ft_topleft(int tetrimino[16], const unsigned int size);
void	ft_top(int tetrimino[]);
void	ft_left(int *tetrimino, const unsigned int size);
void	ft_error(void);
void	ft_inil_tetr(t_tetr	*tetr, int size);
void	ft_validate(int fd, t_tetr *storage);

#endif
