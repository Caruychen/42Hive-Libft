/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:37:10 by cchen             #+#    #+#             */
/*   Updated: 2021/11/10 09:31:26 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static FILE *write_temp_file(const char *str)
{
	int		fd;
	FILE	*file;

	if ((fd = open("temp", O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1)
	{
		fprintf(stderr, "Cannot open temp file\n");
		exit (1);
	}
	ft_putstr_fd(str, fd);
	file = fdopen(fd, "r");
	rewind(file);
	return (file);
}

static int	compare_strings(const char *res, const char *str, size_t length)
{
	if (memcmp(res, str, length) != 0)
	{
		printf("FAILED: Error in ft_putstr_fd\n");
		printf("Used %s, but got %s from file\n", str, res);
		return (-1);
	}
	return (0);
}

static void	clean_up(FILE *file, char *res)
{
	if (fclose(file))
	{
		fprintf(stderr, "Cannot close temp file\n");
		exit (1);
	}
	if (remove("temp"))
	{
		fprintf(stderr, "Could not remove temp file\n");
		exit (1);
	}
	free(res);
}

static int	test_str(const char *str)
{
	char			*res = NULL;
	int				outcome;
	size_t			length = strlen(str) + 1;
	FILE			*file;

	outcome = 0;
	res = (char *)malloc(sizeof(*res) * length);
	file = write_temp_file(str);
	fgets(res, length, file); 
	outcome = compare_strings(res, str, length);
	clean_up(file, res);
	return (outcome);
}

static int	cycle_str_tests(void)
{
	char *arr[] = {
		"Hello World",
		"I will bring the pain!",
		"are you ready?",
		"",
		"\t",
		" ",
		"\0",
		"0",
		0};
	int	index = 0;

	while (arr[index])
	{
		if (test_str(arr[index]) == -1)
			return (-1);
		++index;
	}
	return (0);
}

int	test_putstr_fd(void)
{
	int	outcome = 0;

	outcome = cycle_str_tests() || outcome;
	return (-outcome);
}
