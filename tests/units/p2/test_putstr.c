/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:36:22 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 17:19:09 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	compare_results(const char *str, const int fd)
{
	FILE	*file;
	char	*res;
	size_t	length = strlen(str) + 1;
	int	outcome;

	outcome = 0;
	res = (char *)malloc(sizeof(*res) * length);
	file = fdopen(fd, "r");
	rewind(file);
	getdelim(&res, &length, 0, file);
	if (memcmp(str, res, length) != 0)
	{
		printf("FAILED: Error in ft_putstr\n");
		printf("Used: %s\n Got: %s\n", str, res);
		outcome = -1;
	}
	fr_clean_up(file, res);
	return (outcome);
}

static int	test_str(const char *str)
{
	int	file_desc;
	int	copy_out;
	int	outcome;

	outcome = 0;
	init_redirect(&file_desc, &copy_out);
	ft_putstr(str);
	reset_output(&copy_out);
	outcome = compare_results(str, file_desc);
	return (outcome);
}

static int	cycle_str_tests(void)
{
	int	index;
	char	*arr[] = {
		"Hello World",
		"Foo",
		"",
		"\n",
		"\0",
		"\t",
		"\nHello\n\tWorld",
		0};
	
	index = 0;
	while (arr[index])
	{
		if (test_str(arr[index]) == -1)
			return (-1);
		++index;
	}
	return (0);
}

int	test_putstr(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_str_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
