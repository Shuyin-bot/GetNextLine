/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:49:30 by sqian             #+#    #+#             */
/*   Updated: 2025/12/11 17:09:52 by sqian            ###   ########.fr       */
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
	char	buf[BUFFER_SIZE + 1];
	ssize_t	r_bytes;
	char	*temp;

	while (1)
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		// printf("read %zi bytes\n", r_bytes);
		if (r_bytes <= 0)
			break ;
		buf[r_bytes] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = ft_strjoin(stash, buf);
		// printf("temp is %s\n", temp);
		free (stash);
		stash = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

char	*get_line(char	*stash)
{
	char	*line;

}

char	*get_next_line(ssize_t	fd)
{
	char	*stash;
	char	*line;

	stash = malloc(BUFFER_SIZE + 1);
	if (!stash)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), NULL);
	stash = raw_stash(fd, stash);
	// line = get_line(stash);
	return (stash);
}

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


int	main(void)
{
	int			fd;
	static char	*stash;

	fd = open("text1.txt", O_RDONLY);
	if (fd <= 0)
		return (1);
	printf("open sucessfully, fd = %i\n", fd);
	printf("before raw_stash, stash:%s\n", stash);
	stash = raw_stash(fd, stash);
	printf("after raw_stash, stash:%s\n", stash);
	// stash = get_line(stash);
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
