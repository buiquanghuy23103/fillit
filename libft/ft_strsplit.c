/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:38:06 by hbui              #+#    #+#             */
/*   Updated: 2021/12/09 07:27:14 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	transform(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			s[i] = '\0';
			i++;
		}
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	ft_solve(char **split, char *dup, int str_len)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < str_len)
	{
		while (i < str_len && !dup[i])
			i++;
		if (i < str_len)
		{
			split[c] = ft_strdup(dup + i);
			if (!split[c])
				ft_tabdel((void **) split);
			c++;
		}
		while (i < str_len && dup[i])
			i++;
	}
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	char	*dup;
	char	**split;

	i = 0;
	if (!s)
		return (NULL);
	dup = ft_strdup(s);
	if (!dup)
		return (NULL);
	split = (char **)ft_memalloc(sizeof(char *) * (transform(dup, c) + 1));
	if (!split)
		return (NULL);
	ft_solve(split, dup, ft_strlen(s));
	free(dup);
	return (split);
}
