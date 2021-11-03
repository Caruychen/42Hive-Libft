/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:48:24 by cchen             #+#    #+#             */
/*   Updated: 2021/11/03 14:59:07 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tests.h"

int	ft_run_tests(void)
{
	if(test_memset() == -1)
		return (-1);
	printf("TESTS OK!\n");
	return (0);
}

int	main(void)
{
	return(ft_run_tests());
}
