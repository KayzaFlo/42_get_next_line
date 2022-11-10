/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:18:35 by fgeslin           #+#    #+#             */
/*   Updated: 2022/11/10 14:24:02 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buf = 0;
	static int		i = 0;
	static ssize_t	read_size = 0;
	static int		eob = 0;
	int				sob;
	char			*str;

	if (!buf)
	{
		buf = malloc(BUFFER_SIZE * sizeof(char));
		if (!buf)
			return (NULL);
		read_size = read(fd, buf, BUFFER_SIZE);
		// if (read_size == 0)
		// {
		// 	free (buf);
		// 	buf = NULL;
		// 	return (NULL);
		// }
		eob = i + read_size;
	}
	str = 0;
	sob = i;
	while (buf[i] != '\n')
	{
		if (i == eob)
		{
			str = ft_strjoin(str, ft_substr(buf, sob, i - sob));
			read_size = read(fd, buf, BUFFER_SIZE);
			// if (read_size == 0)
			// {
			// 	free (buf);
			// 	buf = NULL;
			// 	//free (str);
			// 	return (str);
			// }
			i = 0;
			sob = i;
			eob = i + read_size;
			if (read_size == 0)
			{
				free (buf);
				buf = NULL;
				i = -1;
				break ;
			}
		}
		else
			i++;
	}
	str = ft_strjoin(str, ft_substr(buf, sob, ++i - sob));
	// if (!*str)
	// {
	// 	free (buf);
	//	buf = NULL;
	// 	free (str);
	// 	return NULL;
	// }
	return (str);
}
