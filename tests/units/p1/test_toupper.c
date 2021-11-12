/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:07:16 by cchen             #+#    #+#             */
/*   Updated: 2021/11/12 10:09:33 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_toupper(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_char_is_tests("ft_toupper", ft_toupper, toupper) || outcome;
	print_outcome(outcome, __func__);
	return (outcome);
}
