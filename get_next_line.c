/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:49:30 by sqian             #+#    #+#             */
/*   Updated: 2025/12/12 01:08:16 by sqian            ###   ########.fr       */
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

	while (1)
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		printf("read %zi bytes\n", r_bytes);
		if (r_bytes <= 0)
			break ;
		buf[r_bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		printf("addr of stash before join:%p\n", stash);
		temp = ft_strjoin(stash, buf);
		free (stash);
		stash = temp;
		printf("addr of stash after join:%p\n", stash);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

static char	*get_line(char	*stash)
{
	char	*line;
	size_t	len;

	len = 0;
	while (stash[len] != '\n' && stash[len])
		len++;
	if (stash[len] == '\n')
		len++;
	line = ft_substr(stash, 0, len);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), NULL);
	stash = raw_stash(fd, stash);
	line = get_line(stash);
	return (line);
}

int	main(void)
{
	int			fd;
	static char	*stash;
	char		*line;

	fd = open("text1.txt", O_RDONLY);
	if (fd <= 0)
		return (1);
	printf("open sucessfully, fd = %i\n", fd);
	printf("before raw_stash, stash:%p\n", (void*)stash);
	stash = raw_stash(fd, stash);
	printf("after raw_stash, stash:%p\n", (void*)stash);
	line = get_line(stash);
	printf("line:%s", line);
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
