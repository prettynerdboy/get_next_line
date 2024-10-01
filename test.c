/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:22:28 by anakin            #+#    #+#             */
/*   Updated: 2024/09/04 18:05:05 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>  

char *get_get_next_line(void)
{
    int fd;
    char buff[10];//0以外file_sizeに変化なし。
    char *text;
    size_t buff_size;
    size_t file_size;
    static char* start;
    static char* end;
    size_t line_len;
    char *line;
    
    file_size=0;
    fd=open("sample.txt", O_RDONLY);
    if (fd < 0)
    return(NULL);
    
    printf("fd=%d\n",fd);

    while((buff_size=read(fd,(void*)buff,sizeof(buff)))>0)
        file_size+=buff_size;
    close(fd);
    
    printf("file_size=%zu\n",file_size);
    
    text =(char *)malloc((file_size+1)*sizeof(char));
    fd=open("sample.txt", O_RDONLY);
    read(fd,(void*)text,file_size);
    close(fd);
    text[file_size]='\0';
    
    printf("text_contents\n%s\n",text);
    printf("text_contents\n");
    
    start=text;
    line_len=0;
    while(text[line_len]!='\n')
    {
        line_len++;
    }
    printf("line_len=%zu\n",line_len);
    
    end=start+line_len;
    line=(char*)malloc((line_len+1)*sizeof(char));
    
    printf("start=%s\n",start);
    
    ft_strlcpy(line,start,line_len+1);
    start=end;
    printf("line=%s\n",line);
    return(line);
}

// int main(void)
// {
//     char *test1=get_get_next_line();
//     printf("test1=%s",test1);
//     char *test2=get_get_next_line();
//     printf("test2=%s",test2);
//     char *test3=get_get_next_line();
//     printf("test3=%s",test3);
// }