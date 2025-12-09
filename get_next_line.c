/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:49:30 by sqian             #+#    #+#             */
/*   Updated: 2025/12/09 21:26:22 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	char	*b;

	b = malloc(ft_strlen(s) + 1);
	if (!b)
		return (NULL);
	ft_strlcpy(b, s, ft_strlen(s) + 1);
	return (b);
}

static char	*raw_stash(int fd, char *stash)
{
	int		r_bytes;
	char	*buf;
	char	*temp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	buf[0] = '\0';
	r_bytes = 1;
	while ((!stash || ft_strchr(stash, '\n')) && r_bytes > 0)
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		printf("r_bytes = %d\n", r_bytes);
		if (r_bytes <= 0)
			break ;
		buf[r_bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = ft_strjoin(stash, buf);
		free (stash);
		stash = temp;
	}
	free(buf);
	return (stash);
}

int	main(void)
{
	int		fd;
	char	*stash;

	stash = NULL;
	fd = open("text.txt", O_RDONLY);
	printf("buffer size : %d\n", BUFFER_SIZE);
	if (fd < 0)
	{
		perror("Open has a problem!");
		return (1);
	}
	printf("文件打开成功, fd = %d\n", fd);
	printf("调用raw_stash 之前 stash :%s\n", stash);
	stash = raw_stash(fd, stash);
	printf("调用raw_stash 之后 stash :%s\n", stash);
	if (!stash)
		printf("stash == NULL\n");
	else
	{
		printf("stash :%s\n", stash);
	}
	if (stash)
		free(stash);
	close(fd);
	return (0);
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
//
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
