/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:00:29 by cchen             #+#    #+#             */
/*   Updated: 2021/11/12 15:21:09 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	test_fn_with_int(const char *f_name, const int size, char *(*ft_fptr)(size_t size))
{
	char	testblock[size + 1];
	char	*memblock = ft_fptr(size);
	int		outcome = 0;

	bzero(testblock, size + 1);
	if ((outcome = memcmp(testblock, memblock, size + 1)))
	{
		printf("FAILED: Error in %s, found difference of %d\n", f_name, outcome);
		printf("Did you implement ft_strnew with size + 1?\n");
		outcome = -1;
	}
	free(memblock);
	return (outcome);
}

static int	test_fn_with_invalid(const char *f_name, const int size, char *(*ft_fptr)(size_t size))
{
	char	*memblock = ft_fptr(size);

	if (memblock != NULL)
	{
		printf("FAILED: Error in %s, expected NULL but got non-NULL pointer using size %d\n", f_name, size);
		return (-1);
	}
	return (0);
}

static int	cycle_size_tests(const char *f_name, char *(*ft_fptr)(size_t size))
{
	int	valid[] = {
		0,
		1,
		10,
		42,
		60000};
	int	index = 0;
	int	max = 5;

	while (index < max)
	{
		if (test_fn_with_int(f_name, valid[index], ft_fptr) == -1)
			return (-1);
		if (test_fn_with_int(f_name, sizeof(int) * valid[index], ft_fptr) == -1)
			return (-1);
		++index;
	}
	if (test_fn_with_invalid(f_name, -2, ft_fptr) == -1)
		return (-1);
	return (0);
}

int			test_strnew(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_size_tests("ft_strnew", ft_strnew) || outcome;
	print_outcome(outcome, __func__);
	return (outcome);
}
