/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vecnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:15:26 by cchen             #+#    #+#             */
/*   Updated: 2021/12/20 15:19:47 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_vecnew(void)
{
	t_vec	t1;

	assert(ft_vecnew(&t1, 0, 0) == -1);
	assert(ft_vecnew(&t1, 0, 1) == -1);
	assert(ft_vecnew(&t1, 1, 0) == -1);
	assert(ft_vecnew(&t1, 10, 1) == 10);
	ft_vecfree(&t1);
	return (0);
}
