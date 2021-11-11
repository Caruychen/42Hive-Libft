/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:52:50 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 17:15:44 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_isascii(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_char_is_tests("ft_isascii", ft_isascii, isascii) || outcome;
	print_outcome(outcome, __func__);
	return (outcome);
}
