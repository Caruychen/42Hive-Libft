/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:30:28 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 17:32:03 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_isprint(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_char_is_tests("ft_isprint", ft_isprint, isprint) || outcome;
	print_outcome(outcome, __func__);
	return (outcome);
}
