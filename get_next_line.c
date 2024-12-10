/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:33:00 by ablabib           #+#    #+#             */
/*   Updated: 2024/12/09 20:33:11 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char *buffer)
{
	char	*new_static_buffer;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || !buffer[i + 1])
	{
		free(buffer);
		return (NULL);
	}
	new_static_buffer = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	free(buffer);
	return (new_static_buffer);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_substr(buffer, 0, i + 1);
	else
		line = ft_strdup(buffer);
	return (line);
}

static char	*allocate_buffer(void)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	return (buffer);
}

static char	*read_from_file(int fd, char *buffer, char *static_buffer)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!static_buffer)
			static_buffer = ft_strdup("");
		tmp = ft_strjoin(static_buffer, buffer);
		free(static_buffer);
		static_buffer = tmp;
		if (ft_strchr(static_buffer, '\n'))
			break ;
	}
	if (bytes_read < 0 || (!static_buffer && bytes_read == 0))
	{
		free(static_buffer);
		return (NULL);
	}
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = allocate_buffer();
	if (!buffer)
		return (NULL);
	static_buffer = read_from_file(fd, buffer, static_buffer);
	free(buffer);
	if (!static_buffer)
		return (NULL);
	line = extract_line(static_buffer);
	static_buffer = next_line(static_buffer);
	return (line);
}
