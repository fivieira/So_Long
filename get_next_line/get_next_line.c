/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:44:55 by fivieira          #+#    #+#             */
/*   Updated: 2023/09/29 17:55:24 by fivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*function_name(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = function_name(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}

// char	*ft_get_line(char *temp)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	if (!temp[i])
// 		return (NULL);
// 	while (temp[i] != '\0' && temp[i] != '\n')
// 		i++;
// 	if (temp[i] == '\0')
// 		line = malloc(sizeof(char) * (i + 1));
// 	else
// 		line = malloc(sizeof(char) * (i + 2));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (temp[i] != '\0' && temp[i] != '\n')
// 	{
// 		line[i] = temp[i];
// 		i++;
// 	}
// 	if (temp[i] == '\n')
// 		line[i++] = '\n';
// 	line[i] = '\0';
// 	return (line);
// }

// char	*ft_new_temp(char *temp)
// {
// 	int		i;
// 	int		j;
// 	char	*new_temp;

// 	i = 0;
// 	j = 0;
// 	while (temp[i] != '\0' && temp[i] != '\n')
// 		i++;
// 	if (temp[i] == '\0')
// 	{
// 		free(temp);
// 		return (NULL);
// 	}
// 	new_temp = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
// 	if (!new_temp)
// 		return (NULL);
// 	i = i + 1;
// 	while (temp[i])
// 		new_temp[j++] = temp[i++];
// 	new_temp[j] = '\0';
// 	free(temp);
// 	return (new_temp);
// }

// char	*ft_read_and_join(int fd, char *temp)
// {
// 	char	*buffer;
// 	int		bytes_read;

// 	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	bytes_read = 1;
// 	while (ft_strchr(temp, '\n') == NULL && bytes_read != 0)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read == -1)
// 		{
// 			free(buffer);
// 			free(temp);
// 			return (NULL);
// 		}
// 		buffer[bytes_read] = '\0';
// 		if (!buffer)
// 			return (NULL);
// 		temp = ft_strjoin(temp, buffer);
// 	}
// 	free(buffer);
// 	return (temp);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*temp;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	temp = ft_read_and_join(fd, temp);
// 	if (!temp)
// 		return (NULL);
// 	line = ft_get_line(temp);
// 	temp = ft_new_temp(temp);
// 	return (line);
// }

// int	main(int argc, char *argv[])
// {
// 	(void)argc;

// 	int	fd;

// 	fd = open(argv[1], O_RDONLY);
// 	int i = 0;
// 	printf("%d", fd);
// 	while (i < 20)
// 	{
// 		printf("%s", get_next_line(fd));
// 		i++;
// 	}
// }