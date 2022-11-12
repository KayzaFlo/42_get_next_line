/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:18:35 by fgeslin           #+#    #+#             */
/*   Updated: 2022/11/12 12:23:24 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_setbuf(char **buf, int fd, ssize_t *read_size)
{
	*buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buf)
		return (0);
	*read_size = read(fd, *buf, BUFFER_SIZE);
	if (*read_size <= 0)
	{
		free (*buf);
		*buf = NULL;
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*buf = 0;
	static ssize_t	i = 0;
	static ssize_t	read_size = 0;
	ssize_t			start;
	char			*str;

	if (!buf)
		if (!ft_setbuf(&buf, fd, &read_size))
			return (NULL);
	str = 0;
	start = i;
	while (i <= read_size)
	{
		if (i == read_size)
		{
			str = ft_strnjoin(str, buf + start, i - start);
			read_size = read(fd, buf, BUFFER_SIZE);
			if (read_size <= 0)
			{
				free (buf);
				buf = NULL;
				return (str);
			}
			i = 0;
			start = 0;
			buf[read_size] = 0;
			if (buf[i] == '\n')
				break ;
		}
		else
		{
			if (buf[i] == '\n')
				break ;
			i++;
		}
	}
	str = ft_strnjoin(str, buf + start, ++i - start);
	return (str);
}
