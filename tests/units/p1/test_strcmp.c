/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:44:13 by cchen             #+#    #+#             */
/*   Updated: 2021/11/15 13:51:00 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int

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
