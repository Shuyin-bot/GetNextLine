/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:49:30 by sqian             #+#    #+#             */
/*   Updated: 2025/12/01 23:39:47 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*

*/
static char	*get_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	bytes = 1;
	bytes = read(fd, buf, BUFFER_SIZE);
	buf[bytes] = '\0';
	while (*buf != '\n')
		buf++;
	if (*buf == '\n')
	stash = ft_strjoin(stash, buf);
	free(buf);
	return (stash);
}


char	*get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;

}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = cleaner(stash);

}
// static char	*get_stash(int fd, char *stash)
// {
// 	char	*buffer;
// 	ssize_t	bytes;

// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (free(stash), NULL);
// 	bytes = 1;
// 	while (bytes > 0 && (!stash || ft_strchr(stash, '\n')))
// 	{
// 		bytes = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes < 0)
// 			break;
// 		if (bytes == 0)
// 			break;
// 		buffer[bytes] = '\0';
// 		if (!stash)
// 			stash = ft_strdup("");
// 		stash = ft_strjoin(stash, buffer);
// 		if (!stash)
// 			break;
// 	}
// 	free(buffer);
// 	if (bytes < 0)
// 		return (free(stash), NULL);
// 	return (stash);
// }

// static char	*get_stash(int fd, char *stash)
// {
// 	char	*buffer;
// 	ssize_t	bytes;

// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (free(stash), NULL);
// 	bytes = 1;
// 	while (bytes > 0 && (!stash || ft_strchr(stash, '\n')))
// 	{
// 		bytes = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes < 0)
// 		{
// 			free(buffer);
// 			free(stash);
// 			return (NULL);
// 		}
// 		if (bytes == 0)
// 			break;
// 		buffer[bytes] = '\0';
// 		if (!stash)
// 			stash = ft_strdup("");
// 		stash = ft_strjoin(stash, buffer);
// 	}
// 	free(buffer);
// 	return (stash);
// }
