/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:06:00 by cchen             #+#    #+#             */
/*   Updated: 2021/11/03 20:53:05 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tests.h"

static	void	initialize_arrays(void **s1, void **s2, int length)
{
	int	index;
	int	length;

	index = 0;
	length = 42;
	while (index < length)
	{
		*s1[index] = index + length;
		*s2[index] = index + length;
		++index;
	}
}

static	int	execute_test(void *s1, void *s2, int length)
{
	
	bzero(s1, 42);
	ft_bzero(s2, 42);
	if (memcmp(s1, s2, 42) != 0)
	{ 
		printf("FAILED; Error in ft_bzero.\n");
		printf("bzero: %s ft_bzero: %s\n", s1, s2);
		return (-1);
	}
	return (0);
}

int		test_bzero(void)
{
	char	controlStr[42];
	char	testStr[42];
	int	controlInt[42];
	int	testInt[42];
	int	length;

	length = 42;
	initialize_arrays(&controlStr, &testStr, length);
	initialize_arrays(&controlInt, &testInt, length);
	printf("%s\n", controlStr);
	printf("%s\n", testStr);

	return (0);
}
