/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:57:07 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 14:01:38 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	cycle_isalpha_tests(void)
{
	int	c = 0;
	int	max = 512;

	while (c < max)
	{
		if (test_char_is(c++, "ft_isalpha", ft_isalpha, isalpha) == -1)
			return (-1);
	}
	return (0);
}

int			test_isalpha(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_isalpha_tests() || outcome;
	return (-outcome);
}
