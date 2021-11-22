/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:16:04 by cchen             #+#    #+#             */
/*   Updated: 2021/11/22 15:15:38 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include "testft.h"

static int	compare_results(char *number)
{
	int	res = ft_atoi(number);
	int	control = atoi(number);;

	if (res != control)
	{
		printf("FAILED: Error in ft_atoi.\n");
		printf("Tested string: %s.\n", number);
		printf("Expected: %d, got: %d\n", control, res);
		return (-1);
	}
	return (0);
}

static int	cycle_atoi_tests(void)
{
	char *numbers[] = {
		"-2147483649",
		"-2147483648",
		"-123",
		"-42",
		"-2",
		"-1",
		"-0",
		"0",
		"1",
		"2",
		"42",
		"123",
		"2147483647",
		"2147483648",
		"42 42",
		" 42 ",
		"42x",
		"x42",
		"one",
		"--42",
		"+42",
		"+-42",
		"-+42",
		".",
		"\t42",
		"\nt42",
		"\v42",
		"\f42",
		"\r42",
		"922337203685477581",
		"9223372036854775810",
		"9223372036854775806",
		"9223372036854775807",
		"9223372036854775808",
		"9223372036854775809",
		"-9223372036854775806",
		"-9223372036854775807",
		"-9223372036854775808",
		"-9223372036854775809",
		"-9223372036854775810",
		0 };
	
	return (iterate_str_arr(numbers, compare_results));
}

static int	examine_leading_char(void)
{
	unsigned char	start = 0;
	unsigned char	max = 255;
	char			str[] = " 42";
	int				outcome = 0;
	
	while (start < max)
	{
		str[0] = start++;
		if (compare_results(str) == -1)
			outcome = -1;
	}
	return (outcome);
}

int	test_atoi(void)
{
	int	outcome = 0;

	outcome = cycle_atoi_tests() || outcome;
	outcome = examine_leading_char() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
