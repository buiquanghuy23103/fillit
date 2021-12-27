/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_close_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:03:21 by hbui              #+#    #+#             */
/*   Updated: 2021/12/27 08:25:03 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_open_close_file(const char *path, int oflag,
			void (*handle_error)(void), void (*use)(int fd))
{
	int	fd;

	fd = open(path, oflag);
	if (fd == -1)
		handle_error();
	use(fd);
	if (close(fd) == -1)
		handle_error();
}
