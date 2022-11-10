/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:18:33 by fgeslin           #+#    #+#             */
/*   Updated: 2022/11/10 13:26:06 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h> //DEBUG

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct s_curbuf
{
	int		i;
	char	*str;
}	t_curbuf;

int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *start, char *end);

char	*get_next_line(int fd);

#endif