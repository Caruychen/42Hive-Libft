/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:51:15 by cchen             #+#    #+#             */
/*   Updated: 2021/11/10 10:47:57 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static void	clean_up(FILE * file)
{
	if (fclose(file))
	{
		fprintf(stderr, "Cannot close temp file\n");
		exit (1);
	}
	if (remove ("temp"))
	{
		fprintf(stderr, "Cannot remove temp file\n");
		exit (1);
	}
}

static int	compare_results(const unsigned char c, const int fd)
{
	FILE		*file;
	unsigned char	res;

	file = fdopen(fd, "r");
	rewind(file);
	fscanf(file, "%c", &res);
	if (res != c)
	{
		printf("FAILED: Error in ft_putchar\n");
		printf("Used char %c (%d), but got %c (%d)\n", c, c, res, res);
		return (-1);
	}
	clean_up(file);
	return (0);
}

static int	test_char(const unsigned char c)
{
	int		file_desc;
	int		copy_out;
	int		outcome;

	outcome = 0;
	init_redirect(&file_desc, &copy_out);
	ft_putchar(c);
	reset_output(&copy_out);
	outcome = compare_results(c, file_desc);
	return (outcome);
}

static int	cycle_char_tests(void)
{
	unsigned char max = 255;
	unsigned char index = 0;

	while (index < max)
	{
		if (test_char(index) == -1)
			return (-1);
		++index;
	}
	return (0);
}

int	test_putchar(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_char_tests() || outcome;
	return (-outcome);
}
