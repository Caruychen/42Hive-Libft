/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:54:15 by cchen             #+#    #+#             */
/*   Updated: 2021/11/13 11:55:17 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_striter(void)
{
	int	outcome;
	
	outcome = 0;
	outcome = cycle_striter_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
