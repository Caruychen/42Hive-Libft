/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:39:26 by cchen             #+#    #+#             */
/*   Updated: 2021/11/04 21:40:44 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	run_comparison(const void *s, int c, size_t n)
{
	void	*ret1;
	void	*ret2;

	ret1 = memchr(s, c, n);
	ret2 = ft_memchr(s, c, n);
	if (ret1 != ret2)
	{
		printf("FAILED: Error in test_memchr\n");
		return (-1);
	}
	return (0);
}

int	test_memchr(void)
{
	char	s1[] = "Hello";
	char	s2[] = "";

	run_comparison(s1, 'H', 6);
	run_comparison(s2, 'H', 0);
	return (0);
}
