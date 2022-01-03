/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:17:24 by cchen             #+#    #+#             */
/*   Updated: 2021/11/22 10:03:32 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static char	*init_string(size_t length)
{
	char	*str = (char *)malloc(sizeof(*str) * length);
	bzero(str, length);
	return (str);
}

static void	set_new_str(char *str, size_t length, size_t index)
{
	bzero(str, length);
	memset(str, 'x', index);
}

static int	iterate_s1_lengths(size_t s1_len, size_t s2_len, size_t length, const char *s2)
{
	size_t	index = 0;
	size_t	index2 = 0;
	char	*res = init_string(length);
	char	*control = init_string(length);

	while (index <= s1_len)
	{
		index2 = 0;
		while (index2 < (s2_len * 2))
		{
			set_new_str(res, length, index);
			set_new_str(control, length, index);
			res = ft_strncat(res, s2, index2);
			control = strncat(control, s2, index2);
			if (memcmp(res, control, length))
			{
				printf("FAILED: Error in ft_strncat\n");
				printf("Expected: %s, got :%s\n", control, res);
				free(res);
				free(control);
				return (-1);
			}
			++index2;
		}	
		++index;
	}
	free(res);
	free(control);
	return (0);
}

static int	iterate_s2(const char *s2)
{
	size_t	s1_len = 10;
	size_t	s2_len = strlen(s2);
	size_t	length = s1_len + s2_len + 1;

	return (iterate_s1_lengths(s1_len, s2_len, length, s2));
}

static int	cycle_strncat_tests(void)
{
	const char *s2_arr[] = {
		"", "\0", "foo", "bar", " ", "Hello World", "foo\0bar",
		"foo\nbar", 0 };
	int	index = 0;
	int	outcome = 0;
	while (s2_arr[index])
	{
		if (iterate_s2(s2_arr[index++]) == -1)
			outcome = -1;
	}
	return (outcome);
}

int	test_strncat(void)
{
	int	outcome = 0;

	outcome = cycle_strncat_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
