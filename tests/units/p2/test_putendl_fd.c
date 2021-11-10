/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:55:41 by cchen             #+#    #+#             */
/*   Updated: 2021/11/10 15:34:23 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static void	init_file(int *fd)
{
	if ((*fd = open("temp", O_CREAT|O_TRUNC|O_RDWR, 0666)) == -1)
	{
		fprintf(stderr, "Cannot open temp file\n");
		exit (1);
	}
}

static int	check_result(const char *str, int fd)
{
	char	*res;
	FILE	*file;
	size_t	length = strlen(str) + 2;
	int	outcome;

	outcome = 0;
	res = (char *)malloc(sizeof(*res) * length);
	file = fdopen(fd, "r");
	rewind(file);
	getdelim(&res, &length, 0, file);
	if (memcmp(str, res, length - 2) == 0)
	{
		printf("FAILED: Error in ft_putendl_fd\n");
		printf("Content of string is different.\nExpected: %s\n Got: %s\n", str, res);
		outcome = -1;
	}
	if (res[length - 2] == '\n')
	{
		printf("FAILED: Error in ft_putendl_fd\n");
		printf("Output of ft_putendl_fd does not end with newline\n");
		outcome = -1;
	}
	fr_clean_up(file, res);
	return (outcome);
}

static int	test_str(const char *str, void (*f_ptr)(const char *s, int fd))
{
	int	fd;
	int	outcome;

	outcome = 0;
	init_file(&fd);
	f_ptr(str, fd);
	outcome = check_result(str, fd);
	return (outcome);
}

static int	cycle_str_tests(void)
{
	char *arr[] = {
		"Hello World",
		"\n",
		"\t",
		"\nHello",
		"\nHello\n",
		"\nFoo\nBar\n",
		0};
	int	index;

	index = 0;
	while (arr[index])
	{
		if (test_str(arr[index], ft_putendl_fd) == -1)
			return (-1);
		++index;
	}
	return (0);
}

int	test_putendl_fd(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_str_tests() || outcome;
	return (-outcome);
}
