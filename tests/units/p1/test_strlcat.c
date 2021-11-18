/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:36:18 by cchen             #+#    #+#             */
/*   Updated: 2021/11/18 15:09:46 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static char	*init_string(int length)
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

static int	iterate_s1_lengths(size_t length, const char *s2)
{
	size_t	index = 0;
	char	*res = init_string(length);
	char	*control = init_string(length);
	size_t	res_n;
	size_t	control_n;

	while (index < length)
	{
		set_new_str(res, length, index);
		set_new_str(control, length, index);
		res_n = ft_strlcat(res, s2, length);
		control_n = strlcat(control, s2, length);
		if (res_n != control_n || memcmp(res, control, length))
		{
			printf("FAILED: Error in ft_strlcat.\n");
			printf("Expected string: %s, got: %s\n", control, res);
			printf("Expected return value: %zu, got: %zu\n", control_n, res_n);
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
	
	return (iterate_s1_lengths(length, s2));
}

static int	cycle_strlcat_tests(void)
{
	const char *s2_arr[] = {
		"", "\0", "foo", "bar", " ", "Hello World", "foo\0bar",
		"foo\nbar", 0 };
	int	index = 0;
	int	outcome  = 0;

	while (s2_arr[index])
	{
		if (iterate_s2(s2_arr[index++]) == -1)
			outcome = -1;
	}
	return (outcome);
}

int	test_strlcat(void)
{
	int	outcome = 0;

	outcome = cycle_strlcat_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
