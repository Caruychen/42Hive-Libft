/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strclr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:29:54 by cchen             #+#    #+#             */
/*   Updated: 2021/11/13 13:20:09 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static	int	is_cleared(const char *str, size_t size)
{
	while (size--)
	{
		if (*str++ != 0)
			return (0);
	}
	return (1);
}

static	int	test_str_on_fn(const char *f_name, char *str, void (*ft_fptr)(char *s))
{
	size_t	size = strlen(str) + 1;

	ft_fptr(str);
	if (!is_cleared(str, size))
	{
		printf("FAILED: Error in %s, string not cleared.\n", f_name);
		return (-1);
	}
	return (0);
}

static	int	cycle_str_tests(const char *f_name, void (*ft_fptr)(char *s))
{
	char	s1[] = "x";
	char	s2[] = "xxxx";
	char	s3[] = "\nf\too\vbar";
	char	*arr[] = {
		"",
		s1, s2, s3, 0};
	int	index = 0;
	int	outcome = 0;

	while (arr[index])
	{
		if (test_str_on_fn(f_name, arr[index++], ft_fptr) == -1)
			outcome = -1;
	}
	return (outcome);
}	

int		test_strclr(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_str_tests("ft_strclr", ft_strclr) || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
