/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:18:30 by fgeslin           #+#    #+#             */
/*   Updated: 2022/11/10 14:25:46 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s || len <= 0)
		return (NULL);
	if ((size_t)ft_strlen(s) < len)
		len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (i + start < (size_t)ft_strlen(s))
			str[i] = s[i + start];
		else
			str[i] = 0;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *start, char *end)
{
	char	*str;
	int		i;
	int		j;

	if (!start && !end)
		return (NULL);
	else if (!start)
		return (end);
	else if (!end)
		return (start);
	str = malloc((ft_strlen(start) + ft_strlen(end)) * sizeof(char));
	i = -1;
	while (start[++i])
		str[i] = start[i];
	j = 0;
	while (end[j])
	{
		str[i] = end[j];
		i++;
		j++;
	}
	str[i] = 0;
	free(start);
	free(end);
	return (str);
}
