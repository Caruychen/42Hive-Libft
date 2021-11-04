/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:06:00 by cchen             #+#    #+#             */
/*   Updated: 2021/11/04 12:59:15 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static	void	init_str_arr(char *s1, char *s2, int length)
{
	int	index;

	index = 0;
	while (index < length)
	{
		s1[index] = index + length;
		s2[index] = index + length;
		++index;
	}
}

static	void	init_int_arr(int *s1, int *s2, int length)
{
	int	index;

	index = 0;
	while (index < length)
	{
		s1[index] = index + length;
		s2[index] = index + length;
		++index;
	}
}

static	int	execute_test(void *s1, void *s2, int length)
{
	bzero(s1, length);
	ft_bzero(s2, length);
	if (memcmp(s1, s2, length) != 0)
	{
		printf("FAILED; Error in ft_bzero.\n");
		printf("bzero: %s ft_bzero: %s\n", (char *)s1, (char *)s2);
		return (-1);
	}
	return (0);
}

int	test_bzero(void)
{
	char	controlStr[42];
	char	testStr[42];
	int		controlInt[42];
	int		testInt[42];
	int		length;
	int		outcome;

	outcome = 0;
	length = 42;
	init_str_arr(controlStr, testStr, length);
	init_int_arr(controlInt, testInt, length);
	outcome = execute_test(controlStr, testStr, length);
	outcome = execute_test(controlInt, testInt, sizeof(int) * length) || outcome;
	return (-outcome);
}
