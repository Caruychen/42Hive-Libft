/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:42:47 by cchen             #+#    #+#             */
/*   Updated: 2021/11/15 13:40:49 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	count_zeroes(const char *s, size_t size)
{
	int	count = 0;

	while (size > 0 && s[size - 1] == 0)
	{
		++count;
		--size;
	}
	return (count);
}

static int	check_strncpy_with_size(size_t size, const char *s)
{
	char	*res;
	char	*control;
	int		outcome = 0;

	res = (char *)malloc(sizeof(*res) * size);
	control = (char *)malloc(sizeof(*control) * size);
	res = ft_strncpy(res, s, size);
	control = strncpy(control, s, size);
	if (memcmp(res, control, size) != 0)
	{
		printf("FAILED: Error in strncpy.\n");
		printf("Expected %s, got: %s\n", control, res);
		printf("Expected %d terminating zeros, got: %d\n", count_zeroes(control, size),
				count_zeroes(res, size));
		outcome = -1;
	}
	free(res);
	free(control);
	return (outcome);
}

static int	check_strncpy(char *s)
{
	size_t	cur_size;
	size_t	max;
	int		outcome = 0;

	cur_size = 1;
	max = 42;
	while (cur_size < max)
	{
		if (check_strncpy_with_size(cur_size++, s) == -1)
			outcome = -1;
	}
	return (outcome);
}

static int	cycle_strncpy_tests(void)
{
	char *arr[] = {
		"",
		"Hello World",
		"\n",
		"0",
		"Hello\nWorld",
		0 };
	
	return (iterate_str_arr(arr, check_strncpy));
}

int			test_strncpy(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_strncpy_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
