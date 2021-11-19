/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:38:41 by cchen             #+#    #+#             */
/*   Updated: 2021/11/19 10:28:17 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	compare_result(char *s, char *expected)
{
	char	*res = ft_strtrim(s);	
	size_t	expected_len = strlen(expected) + 1;
	if (memcmp(res, expected, expected_len))
	{
		printf("FAILED: Error in ft_strtrim.\n");
		printf("Expected: %s, got %s.\n", expected, res);
		printf("Expected length: %zu, got: %zu.\n", expected_len - 1,
				strlen(res));
		free(res);
		return (-1);
	}
	return (0);
}

static int	cycle_strtrim_tests(void)
{
	char	*arr1[] = {
		"Foo Bar",
		"Foo  Bar",
		" Foo Bar ",
		"\t Foo\nBar\t\t\n",
		"\n Foo\tBar   ",
		" ",
		"\n",
		"\t",
		" \n",
		" \t",
		"  ",
		"",
		"F\n",
		"\nF",
		" F",
		"\tF",
   		" F " };
	char	*expected[] = {
		"Foo Bar",
		"Foo  Bar",
		"Foo Bar",
		"Foo\nBar",
		"Foo\tBar",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"F",
		"F",
		"F",
		"F",
   		"F" };

	return (iterate_against_expected(arr1, expected, 17, compare_result));
}

int	test_strtrim(void)
{
	int	outcome = 0;

	outcome = cycle_strtrim_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
