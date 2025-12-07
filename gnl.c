/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:52:54 by sqian             #+#    #+#             */
/*   Updated: 2025/12/07 17:14:42 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strjoin(char const *s1, char const *s2, char *stash)
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
		return (free(stash), NULL);
	ft_strlcpy(s, s1, l1 + 1);
	while ()
	s1[l1++] = s2[l2++];
	s1[l1] = '\0';
	return (s);
}
