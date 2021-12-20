/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vecfrom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:59:20 by cchen             #+#    #+#             */
/*   Updated: 2021/12/20 16:01:41 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_vecfrom(void)
{
	t_vec   t1;
	int	base[] = {1, 2, 3, 4, 5};
	
	assert(ft_vecfrom(&t1, base, 5, sizeof(int)) > 0);
	assert(memcmp(t1.memory, base, sizeof(base)) == 0);
	ft_vecfree(&t1);
	return (0);
}

