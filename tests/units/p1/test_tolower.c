/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:09:50 by cchen             #+#    #+#             */
/*   Updated: 2021/11/12 10:14:10 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_tolower(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_char_is_tests("ft_tolower", ft_tolower, tolower) || outcome;
	print_outcome(outcome, __func__);
	return (outcome);
};
