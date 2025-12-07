#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s = malloc(l1 + l2 + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, l1 + 1);
	while (*s)
		return (s++);
	while (*s2)
	{
		*s = *s2;
		s++;
	}
	*(s + 1) = '\0';
	return (s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < size -1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

int	main()
{
	char	*s1 = "Hello";
	char	*s2 = "Pappa wurz";

	char	s;
	printf("%s", ft_strjoin(s1, s2));
}

// int	main()
// {
// 	int	fd = open("text.txt", O_WRONLY);
// 	int	r;
// 	char	buf[10];

// 	printf("open returned(fd):%i\n", fd);
// 	if (fd < 0)
// 	{	perror("Open has a problem!");
// 		return 1;
// 	}
// 	r = read(fd, buf, sizeof(buf));
// 	printf("first read:%i\n", r);
// 	if (r < 0)
// 	{	perror("Read has a problem!");
// 		return 1;
// 	}

// 	r = read(fd, buf, 5);
// 	printf("second read:%i\n", r);
// 	if (r < 0)
// 	{	perror("Read has a problem!");
// 		return 1;
// 	}
// 	r = read(fd, buf, 5);
// 	printf("third read:%i\n", r);

// 	r = read(fd, buf, 5);
// 	printf("fourth read:%i\n", r);

// 	return 0;
// }
