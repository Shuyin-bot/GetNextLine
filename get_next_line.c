/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:49:30 by sqian             #+#    #+#             */
/*   Updated: 2025/12/06 21:41:36 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*get_stash(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes;

	bytes = 1;
	while (!stash && !ft_strchr(stash, '\n') && bytes != 0)
	{
		bytes = read (fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(stash), NULL);
		buf[bytes] = '\0';
		// 将缓冲区内容追加到stash
		stash = ft_strjoin(stash, buf, stash);
		// 旧stash被释放，新stash包含所有数据
	}
	return (stash);
}

int	main()
{
	int		fd;
	char	*stash = NULL;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{	perror("Open has a problem!");
		return 1;
	}
	stash = get_stash(fd, stash);
	if (!stash)
		printf("stash == NULL\n");
	else
		printf("stash :%s\n", stash);
		free(stash);
	close(fd);
}


// char	*get_line(char *stash)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	if (!stash || !stash[0])
// 		return (NULL);
// 	while (stash[i] && stash[i] != '\n')
// 		i++;

// }
// /*
// line 58: if get_stash failed, e.g. read == -1
// e.g.
// */
// char	*get_next_line(int fd)
// {
// 	static char	*stash;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	stash = get_stash(fd, stash);
// 	if (!stash)
// 		return (NULL);
// 	line = get_line(stash);
// 	if (!line || *line == '\0')

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
// 		if (!stash)
// 			break;
// 	}
// 	free(buffer);
// 	if (bytes < 0)
// 		return (free(stash), NULL);
// 	return (stash);
// }
