/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:08:12 by cchen             #+#    #+#             */
/*   Updated: 2021/11/16 12:20:59 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	run_comparison(const char *s, int c)
{
	char	*res;
	char	*control;

	res = ft_strchr(s, c);
	control = strchr(s, c);
	if (res != control)
	{
		printf("FAILED: Error in ft_strchr.\n");
		printf("looking for %c (%d) Using string: %s\n", c, c, s);
		printf("Expected %p, got %p\n", control, res);
		return (-1);
	}
	return (0);
}

static int	cycle_strchr_tests(void)
{
	char	*s = "The quick brown fox,\njumped over the lazy white dog.\0foo";
	int		index = 0;
	int		outcome = 0;
	
	while (index < 265)
	{
		if (run_comparison(s, index) == -1)
			outcome = -1;
		++index;
	}
	return (outcome);
}

int	test_strchr(void)
{
	int	outcome = 0;

	outcome = cycle_strchr_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
