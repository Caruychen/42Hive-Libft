/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:12:15 by cchen             #+#    #+#             */
/*   Updated: 2021/11/10 10:54:02 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	compare_results(const char *str, const int fd)
{
	FILE	*file;
	char	*res;
	size_t	length = strlen(str) + 2;
	int	outcome;

	outcome = 0;
	res = (char *)malloc(sizeof(*res) * length);
	file = fdopen(fd, "r");
	rewind(file);
	fgets(res, length, file);
	if (memcmp(str, res, length - 2) != 0)
	{
		printf("FAILED: Error in ft_putendl\n");
		printf("Content of string is different.\nUsed: %s\n Got: %s\n", str, res);
		outcome = -1;
	}
	if (res[length] != '\n')
	{
		printf("FAILED: Error in ft_putendl\n");
		printf("Output of ft_putendl does not end with newline\n");
		outcome = -1;
	}
	fr_clean_up(file, res);
	return (outcome);
}

static int	test_str(const char *str, void (*f_ptr)(const char *s))
{
	int	file_desc;
	int	copy_out;
	int	outcome;

	outcome = 0;
	init_redirect(&file_desc, &copy_out);
	f_ptr(str);
	reset_output(&copy_out);
	outcome = compare_results(str, file_desc);
	return (outcome);
}	

static int	cycle_str_tests(void)
{
	int	index;
	char	*arr[] = {
		"Hello World",
		0};

	index = 0;
	while (arr[index])
	{
		if (test_str(arr[index], ft_putendl) == -1)
			return (-1);
		++index;
	}
	return (0);
}

int		test_putendl(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_str_tests() || outcome;
	return (-outcome);
}
