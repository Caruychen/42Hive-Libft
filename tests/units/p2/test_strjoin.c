/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:11:18 by cchen             #+#    #+#             */
/*   Updated: 2021/11/22 15:30:00 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	check_strjoin(char *s1, char *s2)
{
	size_t	len1 = strlen(s1);
	size_t	len2 = strlen(s2);

	char	*str = ft_strjoin(s1, s2);
	int	res1 = memcmp(str, s1, len1);
	int	res2 = memcmp(str + len1, s2, len2);
	if (res1 || res2 || str[len1 + len2])
	{
		printf("FAILED: Error in ft_strjoin.\n");
		printf("Tried joining:\n%s\n%s\n", s1, s2);
		printf("Got: %s\n", str);
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}

int	cycle_strjoin_tests(void)
{
	char	*arr1[] = {
		"The quick brown fox,", " jumped over the lazy white dog",
		"foo", "bar", " ", "", "\0", "\n", "1", "malloc ???" };
	char	*arr2[] = {
		"The quick brown fox,", " jumped over the lazy white dog",
		"foo", "bar", " ", "", "\0", "\n", "1", "where is my " };
	return (iterate_dual_arrays(arr1, arr2, 10, check_strjoin));
}

int	test_strjoin(void)
{
	int	outcome = 0;

	outcome = cycle_strjoin_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
