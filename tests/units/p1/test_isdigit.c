/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:03:31 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 14:08:54 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_isdigit(void)
{
	int	outcome;
	
	outcome = 0;
	outcome = cycle_char_is_tests("ft_isdigit", ft_isdigit, isdigit) || outcome;
	return (-outcome);
}
