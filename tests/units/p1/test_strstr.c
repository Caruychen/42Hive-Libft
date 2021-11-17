/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:17:16 by cchen             #+#    #+#             */
/*   Updated: 2021/11/17 21:46:25 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	run_comparison(const char *haystack, const char *needle)
{
	char	*res;
	char	*control;

	res = ft_strstr(haystack, needle);
	control = strstr(haystack, needle);
	if (res != control)
	{
		printf("FAILED: Error in ft_strstr.\n");
		printf("Looking for %s in string: %s\n", needle, haystack);
		printf("Expected: %p, got: %p\n", control, res);
		return (-1);
	}
	return (0);
}

static int	cycle_strstr_tests(void)
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
	int		outcome = 0;

	while (sub_arr[index])
	{
		if (run_comparison(s, sub_arr[index++]) == -1)
			outcome = -1;
	}
	return (outcome);
}

int			test_strstr(void)
{
	int	outcome = 0;

	outcome = cycle_strstr_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
