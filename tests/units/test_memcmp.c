/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:59:38 by cchen             #+#    #+#             */
/*   Updated: 2021/11/05 10:41:39 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static size_t	find_max(size_t n1, size_t n2)
{
	return (n1 >= n2 ? n1 : n2);
}

static int	run_comparisons(char *s1, char *s2)
{
	size_t	n;
	size_t	index;

	n = find_max(strlen(s1), strlen(s2));
	index = 0;
	while (index < n + 1)
	{
		if (memcmp(s1, s2, index) != ft_memcmp(s1, s2, index))
		{
			printf("FAILED: Error at ft_memcmp\n");
			printf("s1: %s, s2: %s\n", s1, s2);
			return (-1);
		}
		++index;
	}
	return (0);
}

static int	iterate_array_tests(char **arr1, char **arr2, int length)
{
	int index1;
	int index2;
	
	index1 = 0;
	while (index1 < length)
	{
		index2 = 0;
		while (index2 < length)
		{
			if (run_comparisons(arr1[index1], arr2[index2]) == -1)
				return (-1);
			++index2;
		}
		++index1;
	}
	return (0);
}

int	test_memcmp(void)
{
	int	outcome;
	char	*arr1[] = {
		"foo bar", "foo\0bar", "foo", "bar",
		"", "\0", "\200", "a", "A",
		"1"};
	char	*arr2[] = {
		"foo bar", "foo\0bar", "foo", "bar",
		"", "\0", "\200", "a", "A",
		"1"};
	int	length = 10;

	outcome = 0;
	outcome = iterate_array_tests(arr1, arr2, length) || outcome;
	return (-outcome);
}
