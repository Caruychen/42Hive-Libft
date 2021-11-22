/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:53:32 by cchen             #+#    #+#             */
/*   Updated: 2021/11/22 15:56:37 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	test_char(const unsigned char c)
{
	int		fd;
	unsigned char	res;
	int		outcome;

	outcome = 0;
	if ((fd = open("temp", O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1)
	{
		fprintf(stderr, "Cannot open temp file\n");
		exit (1);
	}
	ft_putchar_fd(c, fd);
	FILE *file = fdopen(fd, "r");
	rewind(file);
	fscanf(file, "%c", &res); 
	if (res != c)
	{
		printf("FAILED: Error in ft_putchar_fd\n");
		printf("Used char %c (%d), but got %c (%d)\n", c, c, res, res);
		outcome = -1;
	}
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
	return (outcome);
}

static int cycle_char_tests(void)
{
	unsigned char	max = 255;
	unsigned char	index = 0;

	while (index < max)
	{
		if (test_char(index) == -1)
			return (-1);
		++index;
	}
	return (0);
}

static int	unicode_tests(void)
{
	int	c = L'ø';
	
	if (test_char(c) == -1)
		return (-1);
	return (0);
}

int	test_putchar_fd(void)
{
	int			outcome;

	outcome = 0;
	outcome = cycle_char_tests() || outcome;
	outcome = unicode_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
