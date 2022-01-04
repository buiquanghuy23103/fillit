/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:27:39 by hbui              #+#    #+#             */
/*   Updated: 2022/01/04 12:52:50 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct s_tetr
{
	int	tmino[26][16];
	int	size;
	int	tcount;
}	t_tetr;

void	ft_topleft(int tetrimino[16], const unsigned int size);
void	ft_top(int tetrimino[]);


#endif
