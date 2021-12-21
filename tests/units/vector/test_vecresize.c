/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vecresize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:48:09 by cchen             #+#    #+#             */
/*   Updated: 2021/12/21 11:50:26 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	get_min(int n1, int n2)
{
	return (n1 < n2 ? n1 : n2);
}

static int	run_asserts(size_t new_size)
{
	t_vec	t1;
	int	base[] = {1, 2, 3, 4, 5};
	
	assert(ft_vecfrom(&t1, base, 5, sizeof(int)) > 0);
	assert(ft_vecresize(&t1, new_size) > 0);
	assert(t1.alloc_size == new_size);
	assert(t1.len == (size_t) get_min(5, new_size / sizeof(int)));
	assert(memcmp(t1.memory, base, get_min(sizeof(base), new_size)) == 0);
	ft_vecfree(&t1);
	return (0);
}

int	test_vecresize(void)
{
	run_asserts(100);
	run_asserts(6 * sizeof(int));
	run_asserts(1 * sizeof(int));
	run_asserts(4 * sizeof(int));
	run_asserts(5 * sizeof(int));
	return (0);
}

