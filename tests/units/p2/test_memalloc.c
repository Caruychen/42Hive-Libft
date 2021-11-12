/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:42:12 by cchen             #+#    #+#             */
/*   Updated: 2021/11/12 13:14:04 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_fn_with_int(const char *f_name, const int size, void *(*ft_fptr)(size_t size))
{
	char	testblock[size];
	void	*memblock = ft_fptr(size);
	int		outcome = 0;

	bzero(testblock, size);
	if ((outcome = memcmp(testblock, memblock, size)))
	{
		printf("FAILED: Error in %s, found difference of %d\n", f_name, outcome);
		outcome = -1;
	}
	free(memblock);
	return (outcome);
}

int	test_fn_with_invalid(const char *f_name, const int size, void *(*ft_fptr)(size_t size))
{
	void	*memblock = ft_fptr(size);

	if (memblock != NULL)
	{
		printf("%c\n", *(char *)memblock);
		printf("FAILED: Error in %s, expected NULL but got non-NULL pointer using size %d\n", f_name, size);
		return (-1);
	}
	return (0);
}	

int	cycle_size_tests(const char *f_name, void *(*ft_fptr)(size_t size))
{
	int	valid[] = {
		0,
		1,
		10,
		42,
		60000};
	int	index = 0;
	int max = 5;

	while (index < max)
	{
		if(test_fn_with_int(f_name, valid[index], ft_fptr) == -1)
			return (-1);
		if(test_fn_with_int(f_name, sizeof(int) * valid[index], ft_fptr) == -1)
			return (-1);
		++index;
	}
	if(test_fn_with_invalid(f_name, -1, ft_fptr) == -1)
		return (-1);
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
