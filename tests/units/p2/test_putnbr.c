/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:23:04 by cchen             #+#    #+#             */
/*   Updated: 2021/11/10 22:48:48 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_putnbr(void)
{
	int	nums[] = {
		0,
		1,
		2,
		-1,
		-2,
		42,
		-24,
		10,
		-2147483648,
		2147483647};
	int	index = 0;
	int	max = 10;
	int	outcome = 0;

	while (index < max)
	{
		ft_putnbr(nums[index++]);
		ft_putchar('\n');
	}
	return (outcome);
}
