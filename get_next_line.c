/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:18:35 by fgeslin           #+#    #+#             */
/*   Updated: 2022/11/04 16:44:56 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;

	printf("%d\n", BUFFER_SIZE);
	buf = malloc(10000 * sizeof(char));
	read(fd, buf, 10000);
	return(buf);
}
