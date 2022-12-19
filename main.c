/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:21:08 by fgeslin           #+#    #+#             */
/*   Updated: 2022/11/14 13:57:40 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	print_dec(char *str)
{
	while (*str)
	{
		printf("%.2x ", *str);
		str++;
	}
	printf("\\0\n");
}

void	print_char(char *str)
{
	if (!str)
	{
		printf("(null)\n");
		return ;
	}
	while (*str && str)
	{
		if (*str >= ' ' && *str <= '~')
			printf("%-2c ", *str);
		else
			printf("%.2x ", *str);
		str++;
	}
	printf("\n");
}

int	main(void)
{
	int		fd;
	int		i;
	char	*str;

	fd = open("testfiles/multlinenl.txt", O_RDONLY);
	i = 1;
	str = 0;
	// str = malloc(1);
	// str[0] = 'a';
	// printf("join: %s\n", ft_strnjoin(str, "hello there", 5));
	while ((str = get_next_line(fd)))
	{
		printf("%.2d- %s", i, str);
		// printf("%.2d- ", i);
		// print_char(str);
		free(str);
		i++;
	}
	printf("%.2d- %s\n", i, str);
	close(fd);
	return (0);
}
