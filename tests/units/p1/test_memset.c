/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:40:42 by cchen             #+#    #+#             */
/*   Updated: 2021/11/18 15:30:28 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static char	*initialize_string(size_t length)
{
	char *str;
	str = (char *)malloc(sizeof(*str) * length);
	return (str);
}

static void	fill_strings(char *s1, char *s2, int c, int length)
{
	memset(s1, c, length);
	ft_memset(s2, c, length);
}

static int	cycle_chars(char *s1, char *s2, int index, int length)
{
	size_t	currentInt = 0;
	size_t	maxInt = 512;

	while (currentInt <= maxInt)
	{
		fill_strings(s1, s2, currentInt, index);
		if (memcmp(s1, s2, length) == -1)
		{
			printf("FAILED: Error in ft_memset.\n");
			printf("Expected: %s, got: %s\n", s1, s2);
			return (-1);
		}
		++currentInt;
	}
	return (0);
}

int	cycle_memset_tests(void)
{
	size_t	length = 42;
	char	*controlStr = initialize_string(length);
	char	*testStr = initialize_string(length);
	size_t	index = 0;
	int		outcome = 0;

	while (index <= length)
	{
		bzero(testStr, length);
		bzero(controlStr, length);
		if (cycle_chars(controlStr, testStr, index, length) == -1)
			outcome = -1;
		++index;
	}
	free(controlStr);
	free(testStr);
	return (outcome);
}

int	test_memset(void)
{
	int	outcome = 0;

	outcome = cycle_memset_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
