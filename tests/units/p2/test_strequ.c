/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strequ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:47:49 by cchen             #+#    #+#             */
/*   Updated: 2021/11/16 11:00:46 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	control_strequ(char const *s1, char const *s2)
{
	return (strcmp(s1, s2) ? 0 : 1);
}

static int	run_comparisons(char *s1, char *s2)
{
	int	res;
	int	control;

	res = ft_strequ(s1, s2);
	control = control_strequ(s1, s2);
	if (res != control)
	{
		printf("FAILED: Error at strequ.\n");
		printf("s1: %s, s2: %s\nExpected: %d, got: %d\n", s1, s2, control, res);
		return (-1);
	}
	return (0);
}

static int	cycle_strequ_tests(void)
{
	char *arr1[] = {
		"foo bar", "foo\0bar", "", "\0", "\200", "a", "A", "\n" };
	char *arr2[] = {
		"foo bar", "foo\0bar", "", "\0", "\200", "a", "A", "\n" };

	return (iterate_dual_arrays(arr1, arr2, 8, run_comparisons));
}

int	test_strequ(void)
{
	int	outcome = 0;

	outcome = cycle_strequ_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
