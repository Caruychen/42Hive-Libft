/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strsub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:27:28 by cchen             #+#    #+#             */
/*   Updated: 2021/11/18 17:00:25 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	check_substr(const char *str, size_t start, size_t sub_length)
{
	char	*sub = ft_strsub(str, start, sub_length);
	if (memcmp(sub, str + start, sub_length))
	{
		printf("FAILED: Error in ft_strsub.\n");
		printf("Expected: %.*s, got: %s\n", (int) sub_length, str + start, sub);
		free(sub);
		return (-1);
	}
	free(sub);
	return (0);
}

static int	iterate_str(const char *str)
{
	size_t		length = strlen(str) + 1;
	size_t		str_index = 0;
	size_t		start;
	size_t		sub_length;

	while (str_index < length)
	{
		start = 0;
		while (start <= str_index)
		{
			sub_length = str_index - start;
			if (check_substr(str, start, sub_length) == -1)
				return (-1);
			++start;
		}
		++str_index;
	}
	return (0);
}

static int	cycle_strsub_tests(void)
{
	const char	*arr[] = {
		"The quick brown fox jumped over the lazy white dog.",
		"",
		" ",
		"\0",
		"foo",
		"foo\nbar",
		0 };
	int	outcome = 0;
	int	index = 0;
	
	while (arr[index])
		outcome = iterate_str(arr[index++]);
	return (outcome);
}

int	test_strsub(void)
{
	int	outcome = 0;
	
	outcome = cycle_strsub_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
