/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:08:45 by cchen             #+#    #+#             */
/*   Updated: 2021/11/19 10:25:21 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	iterate_str_arr(char **arr, int (*f)(char *))
{
	int	index = 0;
	int	outcome = 0;

	while (arr[index])
	{
		if (f(arr[index++]) == -1)
			outcome = -1;
	}
	return (outcome);
}

int	iterate_dual_arrays(char **arr1, char **arr2, int length, int (*f)(char *, char *))
{
	int	index1;
	int	index2;
	int	outcome = 0;

	index1 = 0;
	while (index1 < length)
	{
		index2 = 0;
		while (index2 < length)
		{
			if (f(arr1[index1], arr2[index2]) == -1)
				outcome = -1;
			++index2;
		}
		++index1;
	}
	return (outcome);
}

int	iterate_against_expected(char **arr, char **expected, int length, int (*f)(char *, char *))
{
	int	index = 0;
	int	outcome = 0;

	while (index < length)
	{
		if (f(arr[index], expected[index]) == -1)
			outcome = -1;
		++index;
	}
	return (outcome);
}

int	iterate_chars(const char *str, int (*f)(const char *, int))
{
	int	c_index = 0;
	int	outcome = 0;

	while (c_index < 256)
	{
		if (f(str, c_index) == -1)
			outcome = -1;
		++c_index;
	}
	return (outcome);
}
