/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:21:11 by anakin            #+#    #+#             */
/*   Updated: 2024/10/01 23:07:21 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*buff;

	buff = (char *)s;
	while (*buff)
	{
		if (*buff == (char)c)
			return (buff);
		buff++;
	}
	if ((char)c == '\0')
		return (buff);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	size_t			i;
	unsigned char	*dest;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb && size && nmemb > SIZE_MAX / size)
		return (0);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	dest = (unsigned char *)p;
	i = 0;
	while (i < nmemb * size)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
