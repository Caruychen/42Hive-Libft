/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:57:07 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 17:15:35 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int			test_isalpha(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_char_is_tests("ft_isalpha", ft_isalpha, isalpha) || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
