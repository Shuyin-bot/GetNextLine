/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:50:06 by sqian             #+#    #+#             */
/*   Updated: 2025/12/06 21:23:06 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef	struct x
{
	char		*str_buf;
	struct x	*next;
}	y;

char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2, char *stash);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
