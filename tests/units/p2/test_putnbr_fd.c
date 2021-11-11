/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:57:15 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 17:19:04 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	check_putnbr_result_fd(const int num, const int fd)
{
	FILE	*file;
	char	*res;
	size_t	length;
	int		outcome;

	outcome = 0;
	file = fdopen(fd, "r");
	length = fseek(file, 0L, SEEK_SET);
	res = (char *)malloc(sizeof(*res) * length);	
	getdelim(&res, &length, 0, file);
	if (atoi(res) != num)
	{
		printf("FAILED: Error in ft_putnbr_fd\n");
		printf("Expected: %d\n Got: %s\n", num, res);
		outcome = -1;
	}
	fr_clean_up(file, res);
	return (outcome);
}

static int	test_int_fd(const int num, void (*f_ptr)(int n, int fd))
{
	int	fd;
	int	outcome;

	init_file(&fd);
	f_ptr(num, fd);
	outcome = check_putnbr_result_fd(num, fd);
	return (outcome);
}

static int	cycle_int_tests_fd(void)
{
	int	nums[] = {
		0,
		-0,
		1,
		2,
		-1,
		-2,
		42,
		-24,
		10,
		-2147483648,
		2147483647};
	int	index = 0;
	int	max = 11;

	while (index < max)
	{
		if (test_int_fd(nums[index], ft_putnbr_fd) == -1)
			return (-1);
		++index;
	}
	return (0);
}


int			test_putnbr_fd(void)
{
	int	outcome = 0;

	outcome = cycle_int_tests_fd() || outcome;
	print_outcome(outcome, __func__);
	return (outcome);
}
