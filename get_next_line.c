/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:57:53 by anakin            #+#    #+#             */
/*   Updated: 2024/10/01 23:12:00 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*find_newline(int fd, char *str)
{
	char	*buff;
	int		rd_byte;

	buff = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	rd_byte = 1;
	while (!ft_strchr(buff, '\n') && rd_byte != 0)
	{
		rd_byte = read(fd, buff, BUFFER_SIZE);
		if (rd_byte == -1)
		{
			return (free(str), free(buff), NULL);
		}
		buff[rd_byte] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	if (!*str)
	{
		return (free(str), NULL);
	}
	return (str);
}

char	*make_line(char *txt)
{
	char	*newline;
	int		i;

	i = 0;
	while (txt[i] != '\0' && txt[i] != '\n')
		i++;
	newline = (char *)malloc(sizeof(char) * (i + 2));
	if (!newline)
		return (NULL);
	i = 0;
	while (txt[i] != '\n' && txt[i] != '\0')
	{
		newline[i] = txt[i];
		i++;
	}
	newline[i] = '\n';
	newline[i + 1] = '\0';
	return (newline);
}

char	*next_text(char *text)
{
	size_t	i;
	size_t	j;
	char	*newt;

	if (!(ft_strchr(text, '\n')) || !text)
	{
		return (NULL);
	}
	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	newt = (char *)malloc(sizeof(char) * (ft_strlen(text) - i + 1));
	if (!newt)
		return (NULL);
	i++;
	j = 0;
	while (text[i] != '\0')
		newt[j++] = text[i++];
	newt[j] = '\0';
	free(text);
	return (newt);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text = find_newline(fd, text);
	if (!text)
	{
		return (NULL);
	}
	if (ft_strchr(text, '\n'))
		line = make_line(text);
	else
		line = text;
	text = next_text(text);
	return (line);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*re;

// 	// fd = open("sample.txt", O_RDONLY);
// 	// fd = open("41.text", O_RDONLY);
// 	fd = -10;
// 	if (fd < 0)
// 		return (-1);
// 	// printf("fd=%d\n", fd);
// 	// while(1)
// 	// {
// 	//     re=get_next_line(fd);
// 	//     printf("%s",re);
// 	//     if(re==NULL)
// 	//     break ;
// 	// }
// 	while ((re = get_next_line(fd)) != NULL)
// 		{
// 			printf("line=%s", re);
// 			free(re);
// 		}
// 	close(fd);
// 	return (0);
// }
