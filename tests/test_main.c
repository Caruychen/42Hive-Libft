/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:48:24 by cchen             #+#    #+#             */
/*   Updated: 2021/11/04 12:07:55 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	ft_run_tests(void)
{
	int	(*ft_ptr_arr[])(void) = {
		test_memset,
		test_bzero,
		test_memcpy,
		0};
	int	index;

	index = 0;
	while (ft_ptr_arr[index])
	{
		ft_ptr_arr[index++]();
	}		
	printf("TESTS OK!\n");
	return (0);
}

int	main(void)
{
	return (ft_run_tests());
}
