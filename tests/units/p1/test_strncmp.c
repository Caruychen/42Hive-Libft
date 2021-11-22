/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:06:39 by cchen             #+#    #+#             */
/*   Updated: 2021/11/22 10:56:16 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	run_comparisons(char *s1, char *s2)
{
	size_t	n;
	size_t	index;
	int		res;
	int		control;

	n = 8;
	index = 0;
	while (index < n + 1)
	{
		res = ft_strncmp(s1, s2, index);
		control = strncmp(s1, s2, index);
		if (res != control)
		{
			printf("FAILED: Error at ft_strncmp, with length input: %zu.\n", index);
			printf("s1: %s, s2: %s\nExpected: %d, got:%d\n", s1, s2, control, res);
			return (-1);
		}
		++index;
	}
	return (0);
}

static int	cycle_strncmp_tests(void)
{
	char *arr1[] = {
		"foo bar", "foo\0bar", "foo\0foo", "", "\0", "\200", "a", "A", "\n" };
	char *arr2[] = {
		"foo bar", "foo\0bar", "foo\0foo", "", "\0", "\200", "a", "A", "\n" };

	return(iterate_dual_arrays(arr1, arr2, 9, run_comparisons));
}

int			test_strncmp(void)
{
	int	outcome = 0;

	outcome = cycle_strncmp_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
