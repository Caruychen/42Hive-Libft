/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:40:42 by cchen             #+#    #+#             */
/*   Updated: 2021/11/03 11:41:35 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tests.h"
#include <stdio.h>

static void initialize_string(char **str, int length)
{
	*str = NULL;
	*str = (char *)malloc(sizeof(**str) * length);
}

static void fill_strings(char *s1, char *s2, int c, int length)
{
	memset(s1, c, length);
	ft_memset(s2, c, length);
}

int	test_memset(void)
{
	char	*controlStr;
	char	*testStr;
	char	length;

	length = 12;
	initialize_string(&controlStr, length);
	initialize_string(&testStr, length);
	if (controlStr == NULL || testStr == NULL)
		return (1);
	fill_strings(controlStr, testStr, 0, length);
	fill_strings(controlStr, testStr, '.', length);
	printf("after: %s\n", controlStr);
	return (0);
}
