/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:00:05 by anakin            #+#    #+#             */
/*   Updated: 2024/10/01 20:48:01 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);
char	*make_line(char *txt);
char	*find_newline(int fd, char *str);
char	*next_text(char *text);
char	*get_next_line(int fd);

#endif