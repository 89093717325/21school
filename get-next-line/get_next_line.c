/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrender <yrender@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:50:52 by yrender           #+#    #+#             */
/*   Updated: 2021/11/29 08:50:52 by yrender          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_null(char **ptr)
{
	if (*ptr != 0)
	{
		free(*ptr);
		ptr = 0;
	}
}

char	*join_line(int nl_position, char **buffer)
{
	char	*res;
	char	*tmp;

	tmp = 0;
	if (nl_position <= 0 )
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = 0;
			return (0);
		}
		res = *buffer;
		*buffer = 0;
		return (res);
	}
	tmp = ft_substr(*buffer, nl_position, BUFFER_SIZE);
	res = *buffer;
	res[nl_position] = 0;
	*buffer = tmp;
	return (res);
}

char	*read_line(int fd, char **buffer, char *read)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*buffer, '\n');
	tmp = 0;
	bytes_read = 0;
	while (nl == 0)
	{
		bytes_read = read(fd, read, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (join_line(bytes_read, buffer));
		read[bytes_read] = 0;
		tmp = ft_strjoin(*buffer, read);
		free_null(buffer);
		*buffer = tmp;
		nl = ft_strchr(*buffer, '\n');
	}
	return (join_line(nl - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD + 1];
	char		*read;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (0);
	read = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read == 0)
		return (0);
	if (buffer[fd] == 0)
		buffer[fd] = ft_strdup("");
	res = read_line(fd, &buffer[fd], read);
	free_null(&read);
	return (res);
}
