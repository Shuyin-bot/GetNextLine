/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:49:30 by sqian             #+#    #+#             */
/*   Updated: 2025/12/14 01:57:16 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*raw_stash(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	r_bytes;
	char	*temp;

	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	while (!ft_strchr(stash, '\n'))
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		if (r_bytes == 0)
			break ;
		if (r_bytes < 0)
			return (free(stash), NULL);
		buf[r_bytes] = '\0';
		temp = ft_strjoin(stash, buf);
		if (!temp)
			return (free(stash), NULL);
		free (stash);
		stash = temp;
	}
	return (stash);
}

static char	*get_line(char	*stash)
{
	char	*line;
	size_t	linelen;

	linelen = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[linelen] != '\n' && stash[linelen])
		linelen++;
	if (stash[linelen] == '\n')
		linelen += 1;
	line = ft_substr(stash, 0, linelen);
	return (line);
}

static char	*new_stash(char *stash)
{
	size_t	stashlen;
	size_t	linelen;
	char	*temp;

	stashlen = ft_strlen(stash);
	linelen = 0;
	while (stash[linelen] != '\n' && stash[linelen])
		linelen++;
	if (stash[linelen] == '\n')
	{
		temp = ft_substr(stash, linelen + 1, stashlen - (linelen + 1));
		free (stash);
		return (temp);
	}
	else
		return (free(stash), NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = raw_stash(fd, stash);
	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	else
	{
		line = get_line(stash);
		if (!line)
			return (NULL);
		stash = new_stash(stash);
	}
	return (line);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int			fd;
// 	static char	*stash;
// 	char		*line;

// 	fd = open("text1.txt", O_RDONLY);
// 	if (fd <= 0)
// 		return (1);
// 	printf("open sucessfully, fd = %i\n", fd);
// 	printf("before raw_stash, stash:%p\n", (void*)stash);
// 	stash = raw_stash(fd, stash);
// 	printf("after raw_stash, stash:%p\n", (void*)stash);
// 	line = get_line(stash);
// 	printf("line:%s", line);
// 	close(fd);
// 	return (0);
// }
