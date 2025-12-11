/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:49:30 by sqian             #+#    #+#             */
/*   Updated: 2025/12/09 23:26:25 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*returns a pointer to the first occurrence of the character c in the string s*/
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == 0)
		return ((char *)(s + i));
	return (NULL);
}

static char	*raw_stash(int fd, char *stash)
{
	int		r_bytes;
	char	buf[BUFFER_SIZE + 1];
	char	*temp;

	r_bytes = 1;
	while ((!stash || !ft_strchr(stash, '\n')) && r_bytes > 0)
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		if (r_bytes <= 0)
			break ;
		buf[r_bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = ft_strjoin(stash, buf);
		free (stash);
		stash = temp;
	}
	return (stash);
}

int	main(void)
{
	int		fd;
	char	*stash;

	stash = NULL;
	fd = open("text1.txt", O_RDONLY);
	printf("buffer size : %d\n", BUFFER_SIZE);
	if (fd < 0)
	{
		perror("Open has a problem!");
		return (1);
	}
	printf("文件打开成功, fd = %d\n", fd);
	printf("调用raw_stash 之前 stash :%s\n", stash);
	stash = raw_stash(fd, stash);
	if (!stash)
		printf("stash == NULL\n");
	else
	{
		printf("调用raw_stash 之后 stash :%s\n", stash);
	}
	if (stash)
		free(stash);
	close(fd);
	return (0);
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
// line 58: if raw_stash failed, e.g. read == -1
// */
// char	*get_next_line(int fd)
// {
// 	static char	*stash;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	stash = raw_stash(fd, stash);
// 	if (!stash)
// 		return (NULL);
// 	line = get_line(stash);
// 	// if (!line || *line == '\0')
// }
