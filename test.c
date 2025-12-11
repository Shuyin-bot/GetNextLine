/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <sqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:52:54 by sqian             #+#    #+#             */
/*   Updated: 2025/12/09 23:09:33 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

int	main(){
char *a = strdup("hello");
char *b = strdup("world");
char *c = ft_strjoin(a, b);

printf("a:%s\n", a);
printf("b:%s\n", b);
printf("c:%s", c);
}
