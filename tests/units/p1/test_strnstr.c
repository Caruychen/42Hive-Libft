/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:23:06 by cchen             #+#    #+#             */
/*   Updated: 2021/11/17 22:18:01 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	run_comparison(const char *haystack, const char *needle, size_t len)
{
	char	*res;
	char	*control;

	res = ft_strnstr(haystack, needle, len);
	control = strnstr(haystack, needle, len);
	if (res != control)
	{
		printf("FAILED: Error in ft_strnstr using length %zu.\n", len);
		printf("Looking for %s in string: %s\n", needle, haystack);
		printf("Expected: %p, got: %p\n", control, res);
		return (-1);
	}
	return (0);
}

static int	cycle_comparison_lengths(const char *haystack, const char *needle)
{
	size_t	hay_len = strlen(haystack) + 4;
	size_t	index = 0;

	while (index < hay_len)
	{
		if (run_comparison(haystack, needle, index++) == -1)
			return (-1);
	}
	return (0);
}

static int	cycle_strnstr_tests(void)
{
	char	*s = "browbrown The quick brown fox,\njumped over the lazy white dog.\
				  The quick brown fox,\njumped over the lazy while dog.\0foo";
	char	*sub_arr[] = {
		"The quick brown fox",
		"jumped over the lazy white dog",
		"broWn fox",
		"brown  fox",
		"brown\0",
		"\n",
		"\t",
		"1",
		"foo",
		"z",
		"\0",
		"",
		0};
	size_t	index = 0;
	int	outcome = 0;

	while (sub_arr[index])
	{
		if (cycle_comparison_lengths(s, sub_arr[index++]) == -1)
			outcome = -1;
	}
	return (outcome);
}
	

int		test_strnstr(void)
{
	int	outcome = 0;

	outcome = cycle_strnstr_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
