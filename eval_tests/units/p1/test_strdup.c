/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:11:38 by cchen             #+#    #+#             */
/*   Updated: 2021/11/15 11:39:57 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	check_strdup(const char *s)
{
	char	*res;
	char	*control;
	int		outcome = 0;

	res = ft_strdup(s);
	control = strdup(s);

	if (strcmp(res, control) != 0)
	{
		printf("FAILED: Error in strdup.\n");
		printf("Expected: %s, got: %s\n", control, res);
		outcome = -1;
	}
	free(res);
	free(control);
	return (outcome);
}

static int	cycle_strdup_tests(void)
{
	char	*arr[] = {
		"",
		"Hello World",
		"\n",
		"Hello\nWorld",
		0 };
	int		index = 0;
	int		outcome = 0;

	while (arr[index])
	{
		if (check_strdup(arr[index++]) == -1)
			outcome = -1;
	}
	return (outcome);
}

int			test_strdup(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_strdup_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
