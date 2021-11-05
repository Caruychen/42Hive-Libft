/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:40:42 by cchen             #+#    #+#             */
/*   Updated: 2021/11/05 10:43:31 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static void	initialize_string(char **str, int length)
{
	*str = NULL;
	*str = (char *)malloc(sizeof(**str) * length);
}

static void	fill_strings(char *s1, char *s2, int c, int length)
{
	memset(s1, c, length);
	ft_memset(s2, c, length);
}

static int	compare_strings(char *s1, char *s2, int length)
{
	int	index;

	index = 0;
	while (index < length)
	{
		if (s1[index] != s2[index])
		{
			printf("FAILED: Error in ft_memset.\n");
			printf("memset: %s ft_memset: %s\n", s1, s2);
			return (-1);
		}
		++index;
	}
	return (0);
}

static int	cycle_chars(char *s1, char *s2, int index, int length)
{
	int	currentInt;
	int	maxInt;

	currentInt = 0;
	maxInt = 512;
	while (currentInt <= maxInt)
	{
		fill_strings(s1, s2, currentInt, length - index);
		if (compare_strings(s1, s2, length) == -1)
		{
			printf("Tested integer: %d\n", currentInt);
			return (-1);
		}
		++currentInt;
	}
	return (0);
}

int	test_memset(void)
{
	char	*controlStr;
	char	*testStr;
	int		length;
	int		index;

	length = 42;
	initialize_string(&controlStr, length);
	initialize_string(&testStr, length);
	if (controlStr == NULL || testStr == NULL)
		return (-1);
	index = 0;
	while (index <= length)
	{
		fill_strings(controlStr, testStr, 0, length);
		if (cycle_chars(controlStr, testStr, index, length) == -1)
			return (-1);
		++index;
	}
	free(controlStr);
	free(testStr);
	return (0);
}
