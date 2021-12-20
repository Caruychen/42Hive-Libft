/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_veccopy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:43:01 by cchen             #+#    #+#             */
/*   Updated: 2021/12/20 16:44:35 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_veccopy(void)
{
	t_vec	t1;
	t_vec	t2;
	int	base[] = {1, 2, 3, 4, 5};
	
	assert(ft_vecfrom(&t1, base, 5, sizeof(int)) > 0);
	assert(ft_vecnew(&t2, 5, sizeof(int)) > 0);
	assert(ft_veccopy(&t2, &t1) > 0);
	assert(memcmp(t2.memory, base, sizeof(base)) == 0);
	ft_vecfree(&t1);
	ft_vecfree(&t2);
}
