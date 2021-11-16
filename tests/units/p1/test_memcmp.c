/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:59:38 by cchen             #+#    #+#             */
/*   Updated: 2021/11/16 10:17:31 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	run_comparisons(char *s1, char *s2)
{
	size_t	n;
	size_t	index;

	n = find_max_len(s1, s2);
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
	outcome = iterate_dual_arrays(arr1, arr2, length, run_comparisons) || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
