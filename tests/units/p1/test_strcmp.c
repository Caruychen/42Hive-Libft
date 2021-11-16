/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:44:13 by cchen             #+#    #+#             */
/*   Updated: 2021/11/16 08:50:34 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	run_comparisons(char *s1, char *s2)
{
	if (ft_strcmp(s1, s2) != strcmp(s1, s2))
	{
		printf("FAILED: Error at ft_strcmp\n");
		printf("s1: %s, s2: %s\nExpected: %d, got: %d\n", s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));
		return (-1);
	}
	return (0);
}

static int	iterate_arrays(char **arr1, char **arr2, int length)
{
	int	index1;
	int index2;
	int	outcome = 0;

	index1 = 0;
	while (index1 < length)
	{
		index2 = 0;
		while (index2< length)
		{
			if (run_comparisons(arr1[index1], arr2[index2]) == -1)
					outcome = -1;
			++index2;
		}
		++index1;
	}
	return (outcome);
}

static int	cycle_strcmp_tests(void)
{
	char *arr1[] = {
		"foo bar", "foo\0bar", "", "\0", "\200", "a", "A", "\n" };
	char *arr2[] = {
		"foo bar", "foo\0bar", "", "\0", "\200", "a", "A", "\n" };

	return(iterate_arrays(arr1, arr2, 8));
}

int	test_strcmp(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_strcmp_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
