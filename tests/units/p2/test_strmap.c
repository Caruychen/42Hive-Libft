/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:23:41 by cchen             #+#    #+#             */
/*   Updated: 2021/11/15 10:30:01 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static char	ft_increment(char c)
{
	return (c + 1);
}

static int	is_str_incremented(const char *s, const char *res)
{
	while (*s)
	{
		if (*res++ != (*s++ + 1))
			return (0);
	}
	return (1);
}

static int	run_strmap_check(char *s)
{
	char	*res;
	size_t	length = strlen(s);
	int		outcome = 0;

	res = ft_strmap(s, ft_increment);
	if (!is_str_incremented(s, res))
	{
		printf("FAILED: Error in strmap\n");
		printf("Expected all chars incremented by +1 from %s\n", s);
		printf("Got: %s\n", res);
		outcome = -1;
	}
	if (res[length] != s[length])
	{
		printf("FAILED: Error in strmap\n");
		printf("Resulting string not null terminated\n");
		outcome = -1;
	}
	free(res);
	res = NULL;
	return (outcome);
}

static int	cycle_strmap_tests(void)
{
	char	*arr[] = {
		"",
		"Hello World",
		0};

	return (iterate_str_arr(arr, run_strmap_check));
}

int		test_strmap(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_strmap_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
