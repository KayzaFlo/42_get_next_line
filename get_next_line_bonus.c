/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:18:35 by fgeslin           #+#    #+#             */
/*   Updated: 2022/11/14 15:31:43 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_initbuf(t_buf *buf, int fd, char **str, ssize_t *start)
{
	if (!(buf->str))
	{
		buf->str = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf->str)
			return (-1);
		buf->readlen = read(fd, buf->str, BUFFER_SIZE);
		if (buf->readlen <= 0)
		{
			free (buf->str);
			buf->str = NULL;
			return (-1);
		}
	}
	*str = NULL;
	*start = buf->ind;
	return (0);
}

void	ft_buflstdel(t_buf *buflst, t_buf *buf, t_buf **buflstptr)
{
	if (!buflst || !buf || !buflstptr)
		return ;
	if (buflst == buf)
	{
		*buflstptr = buflst->nextbuf;
		(*buflstptr)->fd = -1;
		free(buflst);
		return ;
	}
	while (buflst->nextbuf != buf)
		buflst = buflst->nextbuf;
	buflst->nextbuf = buf->nextbuf;
	//printf("clear: %d %d\n", buflst->fd, buflst->nextbuf);
	free (buf);
}

static char	*ft_clearbuf(t_buf *buf, char **str, t_buf *buflst)
{
	free (buf->str);
	buf->str = NULL;
	if (buf->readlen == -1)
	{
		free (*str);
		*str = NULL;
		ft_buflstdel(buflst, buf, &buflst);
		return (NULL);
	}
	ft_buflstdel(buflst, buf, &buflst);
	return (*str);
}

t_buf	*ft_getbuf(t_buf *buf, int fd)
{
	if (buf->fd == 0)
	{
		buf->fd = fd;
		return (buf);
	}
	while (buf->nextbuf)
	{
		if (buf->fd == fd)
			return (buf);
		else if (buf->nextbuf->fd == fd)
			return (buf->nextbuf);
		else
			buf = buf->nextbuf;
	}
	printf("test\n");
	buf->nextbuf = malloc(sizeof(t_buf));
	buf = buf->nextbuf;
	buf->str = NULL;
	buf->readlen = 0;
	buf->ind = 0;
	buf->fd = fd;
	buf->nextbuf = 0;
	return (buf);
}

void	printptr(t_buf	*ptr)
{
	while (ptr)
	{
		printf("%p->%p\t fd: %d\n", ptr, ptr->nextbuf, ptr->fd);
		ptr = ptr->nextbuf;
	}
	printf("0x0\n");
}

char	*get_next_line(int fd)
{
	static t_buf	*buflstptr = 0;
	t_buf			*buf;
	ssize_t			start;
	char			*str;
	
	printptr(buflstptr);
	if (!buflstptr)
		buflstptr = malloc(sizeof(t_buf));
	buf = ft_getbuf(buflstptr, fd);
	if (ft_initbuf(buf, fd, &str, &start) == -1)
		return (NULL);
	while (buf->ind <= buf->readlen)
	{
		if (buf->ind == buf->readlen)
		{
			str = ft_strnjoin(str, buf->str + start, buf->ind - start);
			buf->readlen = read(fd, buf->str, BUFFER_SIZE);
			buf->ind = 0;
			start = 0;
			if (buf->readlen <= 0)
				return (ft_clearbuf(buf, &str, buflstptr));
			buf->str[buf->readlen] = 0;
		}
		if (buf->str[buf->ind] == '\n')
			break ;
		buf->ind++;
	}
	return (ft_strnjoin(str, buf->str + start, ++buf->ind - start));
}
