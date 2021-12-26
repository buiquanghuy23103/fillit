/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:17:43 by hbui              #+#    #+#             */
/*   Updated: 2021/12/22 07:26:28 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_save(char *buff, char **line)
{
	char	*temp;

	temp = *line;
	*line = ft_strjoin(temp, buff);
	ft_strdel(&temp);
	if (!*line)
		return (-1);
	return (1);
}

static int	ft_read_line(char *buff, char **line)
{
	char	*k;

	k = ft_strchr(buff, '\n');
	if (k)
	{
		*k = '\0';
		if (ft_save(buff, line) == -1)
			return (-1);
		ft_memmove(buff, k + 1, buff + BUFF_SIZE - k);
		return (1);
	}
	if (ft_save(buff, line) == -1)
		return (-1);
	return (0);
}

static int	ft_solve(int fd, char *store[], char **line)
{
	int	ret;

	*line = ft_strdup("");
	if (!*line)
		return (-1);
	while (1)
	{
		if (!store[fd])
		{
			store[fd] = (char *)malloc(sizeof(char) * (1 + BUFF_SIZE));
			if (!store[fd])
				return (-1);
			store[fd][0] = '\0';
		}
		if ((store[fd][0] && ft_set(&ret, ft_read_line(store[fd], line)))
			|| ft_set(&ret, read(fd, store[fd], BUFF_SIZE)) < 0)
			return (ret);
		if (!ret && !store[fd][0])
			return (0);
		store[fd][ret] = '\0';
		if (!ret)
			return (1);
	}
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	static char	*store[FD_MAX];
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || fd >= FD_MAX)
		return (-1);
	ret = ft_solve(fd, store, line);
	if (ret <= 0)
	{
		ft_strdel(&store[fd]);
		ft_strdel(line);
	}
	return (ret);
}
