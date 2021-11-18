/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:06:53 by cchen             #+#    #+#             */
/*   Updated: 2021/11/18 11:31:38 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static char	*init_string(int s1_len, int s2_len)
{
	size_t length = s1_len + s2_len + 1;
	char	*str = (char *)malloc(sizeof(*str) * length);
	bzero(str, length);
	return (str);
}

static int	iterate_s1_lengths(size_t s1_len, size_t s2_len, size_t length, const char *s2)
{
	size_t	index = 0;
	char	*res = init_string(s1_len, s2_len);
	char	*control = init_string(s1_len, s2_len);

	while  (index <= s1_len)
	{
		bzero(res, length);
		bzero(control, length);
		memset(res, 'x', index);
		memset(control, 'x', index);
		res = ft_strcat(res, s2);
		control = strcat(control, s2);
		if (memcmp(res, control, length))
		{
			printf("FAILED: Error in ft_strcat\n");
			printf("Expected: %s, got: %s\n", control, res);
			free(res);
			free(control);
			return (-1);
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

static int	cycle_strcat_tests(void)
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

int	test_strcat(void)
{
	int	outcome = 0;

	outcome = cycle_strcat_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
