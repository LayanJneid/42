/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljunaid <ljunaid@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:37:40 by ljunaid           #+#    #+#             */
/*   Updated: 2025/10/12 15:18:24 by ljunaid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	if (!s)
		return (NULL);
	ch = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*gnl_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	if (!s)
		return (NULL);
	dup = malloc(sizeof(char) * (gnl_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = gnl_strlen(s);
	if (start >= s_len)
		return (gnl_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	x;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	joined = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!joined)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2[x])
		joined[i++] = s2[x++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

// int	main(void)
// {
// 	const char	*text = "hello world what are you doin\n";
// 	char		search;
// 	//char		*result;
// 	search = '\n';
// 	printf ("%s",gnl_strchr(text, search));
//------------------------

// char *s= "HI HI LAYAN";
// char *copy;

// copy = gnl_strdup(s);

// printf("%s\n",copy);
// printf("%s",s);

// free(copy);

//------------------------------

// printf("%s",gnl_substr("HI HOW ARE YOU TODAY", 4 , 6));

// --------------------------------

// printf("%s", gnl_strjoin("HELLO ", "THERE"));

// }

// int main (){
//     int fd;

//     fd = open("file44.txt", O_RDWR | O_CREAT |O_APPEND);

//     printf("fd of the file %d \n", fd);

//     dup2(fd, 1);
//     // write(1, "HI", 5);
//     write(fd, "HI ", 5);

//     return (0);
// }

//  int main(){
//     int fd;
//     char buf[256];
//     int chars_read;

//     fd = open("file.txt", O_RDONLY);

//     while ((chars_read = read(fd, buf,30))){
//         buf[chars_read] = '\0';
//         printf("%s" , buf);
//     }
//  }

//  int main(){
//     int fd;
//     char buf[256];
//     int chars_read;

//     fd = open("file.txt", O_RDONLY);

//     while (read(fd,buf,30)){
//         buf[30] = '\0';
//         printf("%s" , buf);
//     }
//  }
