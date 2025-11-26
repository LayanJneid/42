/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljunaid <ljunaid@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:37:43 by ljunaid           #+#    #+#             */
/*   Updated: 2025/11/19 15:53:40 by ljunaid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_join(int fd, char *buf, char *string)
{
	int		bytes_to_read;

	bytes_to_read = 1;
	while ((!gnl_strchr(string, '\n')) && bytes_to_read > 0)
	{
		bytes_to_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_to_read < 0)
		{
			free(string);
			return (NULL);
		}
		if (bytes_to_read == 0)
			break ;
		buf[bytes_to_read] = '\0';
		string = gnl_strjoin(string, buf);
		if (!string)
			return (NULL);
	}
	return (string);
}

static char	*read_line(int fd, char *string)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!string)
	{
		string = gnl_strdup("");
		if (!string)
		{
			free(buf);
			return (NULL);
		}
	}
	string = read_and_join(fd, buf, string);
	free(buf);
	return (string);
}

static char	*extract_line(char *string)
{
	char	*new;
	int		len;

	if (!string)
		return (NULL);
	if (gnl_strchr(string, '\n'))
		len = gnl_strchr(string, '\n') - string; /*+1*/
	else
		len = gnl_strlen(string);
	new = gnl_substr(string, 0, len);
	return (new);
}

static char	*get_rest(char *string)
{
	char	*rest_line;
	char	*newline_ptr;
	int		rest_string_len;
	int		start;

	newline_ptr = gnl_strchr(string, '\n');
	if (newline_ptr)
	{
		start = (newline_ptr - string) + 1;
		rest_string_len = gnl_strlen(string) - start;
		rest_line = gnl_substr(string, start, rest_string_len);
	}
	else
	{
		free(string);
		return (NULL);
	}
	free(string);
	return (rest_line);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = read_line(fd, string);
	if (!string)
		return (NULL);
	line = extract_line(string);
	string = get_rest(string);
	if (!line || line[0] == '\0')
	{
		free(line);
		free(string);
		return (NULL);
	}
	return (line);
}
