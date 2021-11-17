/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:40:47 by cchen             #+#    #+#             */
/*   Updated: 2021/11/17 11:18:41 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	run_comparison(const char *s, int c)
{
	char	*res;
	char	*control;

	res = ft_strrchr(s, c);
	control = strrchr(s, c);
	if (res != control)
	{
		printf("FAILED: Error in ft_strrchr.\n");
		printf("looking for %c (%d) Using string %s\n", c, c, s);
		printf("Expected %p, got %p\n", control, res);
		return (-1);
	}
	return (0);
}

static int	cycle_strrchr_tests(void)
{
	char	*s = "The quick brown fox,\njumped over the lazy white dog.\
				  The quick brown fox,\njumped over the lazy while dog.\0foo";

	return (iterate_chars(s, run_comparison));
}

int			test_strrchr(void)
{
	int	outcome = 0;

	outcome = cycle_strrchr_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
