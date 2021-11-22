/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:39:26 by cchen             #+#    #+#             */
/*   Updated: 2021/11/22 11:30:30 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	run_comparison(const void *s, int c, size_t n)
{
	void	*ret1;
	void	*ret2;

	ret1 = memchr(s, c, n);
	ret2 = ft_memchr(s, c, n);
	if (ret1 != ret2)
	{
		printf("FAILED: Error in test_memchr\n");
		return (-1);
	}
	return (0);
}

static int	iterate_tests(const void *s, int c, size_t n)
{
	size_t	index;
	int	res;

	index = 0;
	while (index < n)
	{
		if ((res = run_comparison(s, c, index)) == -1)
			return (res);
		++index;
	}
	return (0);
}

int	test_memchr(void)
{
	char	s1[] = "foo bar";
	char	s2[] = "";
	int	outcome;

	outcome = 0;
	outcome = iterate_tests(s1, 'f', 8) || outcome;
	outcome = iterate_tests(s2, 'f', 8) || outcome;
	outcome = iterate_tests(s1, 'b', 8) || outcome;
	outcome = iterate_tests(s2, 'b', 8) || outcome;
	outcome = iterate_tests(s1, 'x', 8) || outcome;
	outcome = iterate_tests(s2, 'x', 8) || outcome;
	outcome = iterate_tests(s1, 0, 8) || outcome;
	outcome = iterate_tests(s2, 0, 8) || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
