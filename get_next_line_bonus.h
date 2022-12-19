/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:18:33 by fgeslin           #+#    #+#             */
/*   Updated: 2022/11/12 16:01:53 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h> //DEBUG

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_buf
{
	char			*str;
	ssize_t			readlen;
	ssize_t			ind;
	int				fd;
	struct s_buf	*nextbuf;
}	t_buf;

char	*get_next_line(int fd);

char	*ft_strnjoin(char *s1, const char *s2, int s2_size);

#endif
