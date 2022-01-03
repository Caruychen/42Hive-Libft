/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:00:31 by cchen             #+#    #+#             */
/*   Updated: 2021/11/21 12:50:54 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	check_results(int n)
{
	char	*res = ft_itoa(n);
	if (atoi(res) != n)
	{
		printf("FAILED: Error in ft_itoa.\n");
		printf("Expected: %d, got: %s\n", n, res);
		free(res);
		return (-1);
	}
	free(res);
	return (0);
}

static int	cycle_itoa_tests(void)
{
	int	index = -42;
	int	max = 42;
	int	outcome = 0;

	while (index < max)
	{
		if (check_results(index) == -1)
			outcome = -1;
		++index;
	}
	outcome = check_results(-2147483648) || outcome;
	outcome = check_results(2147483647) || outcome;
	return (-outcome);
}

int	test_itoa(void)
{
	int	outcome = 0;

	outcome = cycle_itoa_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
