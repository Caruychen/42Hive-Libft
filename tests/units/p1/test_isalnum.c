/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:29:10 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 17:15:27 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_isalnum(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_char_is_tests("ft_isalnum", ft_isalnum, isalnum) || outcome;
	print_outcome(outcome, __func__);
	return (outcome);
}
