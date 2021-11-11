/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:48:24 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 10:58:20 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	ft_run_tests(void)
{
	int	(*ft_ptr_arr1[])(void) = {
		test_memset,
		test_bzero,
		test_memcpy,
		test_memccpy,
		test_memmove,
		test_memchr,
		test_memcmp,
		test_strlen,
		0};
	int	(*ft_ptr_arr2[])(void) = {
		test_putchar,
		test_putstr,
		test_putendl,
		test_putnbr,
		test_putchar_fd,
		test_putstr_fd,
		test_putnbr_fd,
		0};
	int	index;

	index = 0;
	while (ft_ptr_arr1[index])
		ft_ptr_arr1[index++]();
	printf("PART 1 TESTS OK!\n");
	index = 0;
	while (ft_ptr_arr2[index])
		ft_ptr_arr2[index++]();
	printf("PART 2 TESTS OK!\n");
	return (0);
}

int	main(void)
{
	return (ft_run_tests());
}
