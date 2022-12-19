/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:21:08 by fgeslin           #+#    #+#             */
/*   Updated: 2022/11/12 15:41:41 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

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
	int		fd1;
	int		fd2;
	int		fd3;
	int		i;
	char	*str;

	fd1 = open("testfiles/multlinenl.txt", O_RDONLY);
	fd2 = open("testfiles/toread.txt", O_RDONLY);
	fd3 = open("testfiles/1char.txt", O_RDONLY);
	i = 1;
	str = 0;
	printf("%d %d %d\n", fd1, fd2, fd3);
	while (i < 8)
	{
		str = get_next_line(fd1);
		printf("%.2d- %s\n", i, str);
		free(str);
		str = get_next_line(fd2);
		printf("%.2d- %s\n", i, str);
		free(str);
		str = get_next_line(fd3);
		printf("%.2d- %s\n", i, str);
		free(str);
		i++;
	}
	//printf("%.2d- %s\n", i, str);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
