/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:54:15 by cchen             #+#    #+#             */
/*   Updated: 2021/11/13 14:58:25 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static void	flip_x(char *str)
{
	*str = 'x';
}

static int	is_str_x(char *str)
{
	while (*str)
	{
		if (*str++ != 'x')
			return (0);
	}
	return (1);
}

static int	run_striter_check(char *str)
{
	ft_striter(str, flip_x);
	if (!is_str_x(str))
	{
		printf("FAILED: Error in striter.\n");
		printf("Expected only x in string, Got %s\n", str); 
		return (-1);
	}
	return (0);
}

static int	cycle_striter_tests(void)
{
	char	s1[] = "";
	char	s2[] = "x";
	char	s3[] = "Hello World";
	char	*arr[] = { s1, s2, s3, 0 };
	int	index = 0;
	int	outcome = 0;

	while (arr[index])
	{
		if (run_striter_check(arr[index++]) == -1)
			outcome = -1;
	}
	return (outcome);
}

#include "testft.h"

int	test_striter(void)
{
	int	outcome;
	
	outcome = 0;
	outcome = cycle_striter_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
