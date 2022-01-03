/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:23:04 by cchen             #+#    #+#             */
/*   Updated: 2021/11/13 11:56:23 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	check_putnbr_result(const int num, const int fd)
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
		printf("FAILED: Error in ft_putnbr\n");
		printf("Expected: %d\n Got: %s\n", num, res);
		outcome = -1;
	}
	fr_clean_up(file, res);
	return (outcome);
}

static int	test_int(const int num, void (*f_ptr)(int n))
{
	int		file_desc;
	int		copy_out;
	int		outcome;

	init_redirect(&file_desc, &copy_out);
	f_ptr(num);
	reset_output(&copy_out);
	outcome = check_putnbr_result(num, file_desc);
	return (outcome);
}

static int	cycle_int_tests(void)
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
		if (test_int(nums[index], ft_putnbr) == -1)
			return (-1);
		++index;
	}
	return (0);
}

int	test_putnbr(void)
{
	int	outcome = 0;

	outcome = cycle_int_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
