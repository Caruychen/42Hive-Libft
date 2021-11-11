/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:41:48 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 17:17:37 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	iterate_comparisons(char **arr)
{
	while (*arr != 0)
	{
		if (strlen(*arr) != ft_strlen(*arr))
		{
			printf("FAILED: Error at ft_strlen when comaring %s\n", *arr);
			return (-1);
		}
		++arr;
	}
	return (0);
}

int	test_strlen(void)
{
	int	outcome;
	char *arr[] = {"Hello World", "Hello\0World", "", "\0", "0", 0};

	outcome = 0;
	outcome = iterate_comparisons(arr) || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
