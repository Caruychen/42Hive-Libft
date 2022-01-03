/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnequ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:08:22 by cchen             #+#    #+#             */
/*   Updated: 2021/11/16 11:18:29 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	control_strnequ(char *s1, char *s2, size_t n)
{
	return (strncmp(s1, s2, n) ? 0 : 1);
}

static int	run_comparisons(char *s1, char *s2)
{
	size_t	n;
	size_t	index;
	int		res;
	int		control;

	n = find_max_len(s1, s2);
	index = 0;
	while  (index < n + 1)
	{
		res = ft_strnequ(s1, s2, index);
		control = control_strnequ(s1, s2, index);
		if (res != control)
		{
			printf("FAILED: Error at ft_strnequ, with length %zu.\n", index);
			printf("s1: %s, s2: %s\nExpected: %d, got %d\n", s1, s2, control, res);
			return (-1);
		}
		++index;
	}
	return (0);
}

static int	cycle_strnequ_tests(void)
{
	char *arr1[] = {
		"foo bar", "foo\0bar", "", "\0", "\200", "a", "A", "\n" };
	char *arr2[] = {
		"foo bar", "foo\0bar", "", "\0", "\200", "a", "A", "\n" };

	return (iterate_dual_arrays(arr1, arr2, 8, run_comparisons));
}

int			test_strnequ(void)
{
	int	outcome = 0;

	outcome = cycle_strnequ_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
