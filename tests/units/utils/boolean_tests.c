/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:09:48 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 14:40:30 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_char_is(const char c, const char *f_name, int (*ft_fptr)(int c), int (*fptr)(int c))
{
	int	ft_res;
	int	res;
	int	outcome = 0;

	ft_res = ft_fptr(c);
	res = fptr(c);
	if (ft_res != res)
	{
		printf("FAILED: Error in %s.\n", f_name);
		printf("Expected: %c (%d), Got %c (%d)\n", ft_res, ft_res, res, res);
		outcome = -1;
	}
	return (outcome);
}

int	cycle_char_is_tests(const char *f_name, int (*ft_fptr)(int c), int (*fptr)(int c))
{
	int	c = -127;
	int	max = 512;

	while (c < max)
	{
		if (test_char_is(c++, f_name, ft_fptr, fptr) == -1)
			return (-1);
	}
	return (0);
}

