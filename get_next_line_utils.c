/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:49:52 by sqian             #+#    #+#             */
/*   Updated: 2025/12/09 22:41:16 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

/*复制一个字符串，并 返回 malloc 出来的新字符串。*/
char	*ft_strdup(const char *s)
{
	char	*b;

	b = malloc(ft_strlen(s) + 1);
	if (!b)
		return (NULL);
	ft_strlcpy(b, s, ft_strlen(s) + 1);
	return (b);
}

/*malloc 一个新字符串，把两个字符串拼在一起。*/
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
	ft_strlcat(s, s2, l1 + l2 + 1);
	return (s);
}

/*把 src 内容复制到 你自己给的 buffer 里。*/
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

/*往 buffer 的 尾部追加字符串（append）*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	total_len;

	dst_len = 0;
	src_len = 0;
	total_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	total_len = dst_len + ft_strlen(src);
	if (dst_len < dstsize)
	{
		while (src[src_len] && dst_len + 1 < dstsize)
			dst[dst_len++] = src[src_len++];
		dst[dst_len] = '\0';
	}
	return (total_len);
}

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
