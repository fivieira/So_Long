/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:44:55 by fivieira          #+#    #+#             */
/*   Updated: 2023/10/12 18:24:24 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_memory(char **stash, char **buffer)
{
	free(*stash);
	free(*buffer);
	return (NULL);
}

char	*store_leftovers(char *stash)
{
	char	*leftover;
	int		len;
	int		skip;

	leftover = NULL;
	len = gnl_strclen(stash, '\0');
	if (gnl_strchr(stash, '\n'))
		skip = gnl_strclen(stash, '\n');
	else if (gnl_strchr(stash, '\0'))
		skip = len;
	else
		skip = 0;
	leftover = gnl_strndup(stash + skip, len - skip);
	free(stash);
	if (!leftover)
		return (NULL);
	if (leftover[0] == '\0')
	{
		free (leftover);
		return (NULL);
	}
	return (leftover);
}

char	*read_file(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	*buffer = 0;
	while (bytes_read != 0 && !gnl_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (clean_memory(&buffer, &stash));
		buffer[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buffer);
	}
	if (bytes_read == -1 || *stash == '\0')
		return (clean_memory(&buffer, &stash));
	free(buffer);
	return (stash);
}

char	*get_new_line(char *stash)
{
	int		len;
	char	*new_line;

	len = gnl_strclen(stash, '\n');
	new_line = malloc(sizeof(char) * (len + 2));
	if (!new_line)
		return (NULL);
	if (stash[0] != '\n')
		gnl_strncpy(new_line, stash, len);
	else
		gnl_strncpy(new_line, "\n", 2);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = NULL;
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	next_line = get_new_line(stash[fd]);
	if (!next_line)
		return (NULL);
	stash[fd] = store_leftovers(stash[fd]);
	return (next_line);
}
