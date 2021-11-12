/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:42:12 by cchen             #+#    #+#             */
/*   Updated: 2021/11/12 11:26:01 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_int_fn(const char *f_name, const int size, void *(*ft_fptr)(size_t size))
{
	char	testblock[sizeof(int) * size];
	void	*memblock = ft_fptr(sizeof(int) * size);
	int		outcome = 0;

	bzero(testblock, sizeof(int) * size);
	if ((outcome = memcmp(testblock, memblock, sizeof(int) * size)))
	{
		printf("FAILED: Error in %s, found difference of %d\n", f_name, outcome);
		outcome = -1;
	}
	free(memblock);
	return (outcome);
}

int	cycle_size_tests(const char *f_name, void *(*ft_fptr)(size_t size))
{
	int	valid[] = {
		1,
		10,
		42,
		60000,
		0};
	int	index = 0;

	while (valid[index])
	{
		if(test_int_fn(f_name, valid[index++], ft_fptr) == -1)
			return (-1);
	}
	return (0);
}

int	test_memalloc(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_size_tests("ft_memalloc", ft_memalloc) || outcome;
	print_outcome(outcome, __func__);
	return (outcome);
}
