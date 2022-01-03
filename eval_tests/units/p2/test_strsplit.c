/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:02:04 by cchen             #+#    #+#             */
/*   Updated: 2021/11/24 08:20:46 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static void	clear_arr(char **res)
{
	char **temp = res;
	
	while (*temp)
		free(*temp++);
	free(res);
}

static int	check_test_sample(char **s)
{
	char	**save = s;
	char	**res = ft_strsplit(*s++, '*');
	char	**res_temp = res;
	if (*s == 0)
	{
		if (*res_temp != 0)
		{
			printf("FAILED: Error in ft_strsplit.\n");
			printf("Tested string: %s, with delim: %c\n", *save, '*');
			printf("Expected NULL, got: %s\n", *res_temp);
			free(res_temp);
			return (-1);
		}
	}
	while (*s)
	{
		if (strcmp(*res_temp, *s))
		{
			printf("FAILED: Error in ft_strsplit.\n");
			printf("Tested string: %s, with delim: %c\n", *save, '*');
			printf("Expected: %s, got: %s\n", *s, *res_temp);
			clear_arr(res);
			return (-1);
		}
		++s;
		++res_temp;
	}
	clear_arr(res);
	return (0);
}

static int	cycle_strsplit_tests(void)
{
	char *s1[] = { "*hello*fellow***students*", "hello", "fellow", "students" , 0 };
	char *s2[] = { "foo", "foo", 0 };
	char *s3[] = { "f", "f", 0 };
	char *s4[] = { "", 0 };
	char *s5[] = { "*", 0 };
	char *s6[] = { "*foo*", "foo", 0 };
	char **arr[] = {
		s1, s2, s3, s4, s5, s6, 0 };
	int	index = 0;
	int	outcome = 0;

	while (arr[index])
	{
		if (check_test_sample(arr[index++]) == -1)
			outcome = -1;
	}
	return (outcome);
}

int	test_strsplit(void)
{
	int	outcome = 0;

	outcome = cycle_strsplit_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
