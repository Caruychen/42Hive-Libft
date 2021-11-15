/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:27:58 by cchen             #+#    #+#             */
/*   Updated: 2021/11/15 11:38:33 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	check_strcpy(const char *s)
{
	char	*res;
	char	*control;
	size_t	length = strlen(s);
	int		outcome = 0;

	res = (char *)malloc(sizeof(*res) * (length + 1));
	control = (char *)malloc(sizeof(*control) * (length + 1));
	res = ft_strcpy(res, s);
	control = strcpy(control, s);
	if (strcmp(res, control) != 0)
	{
		printf("FAILED: Error in strcpy.\n");
		printf("Expected: %s, got: %s\n", control, res);
		outcome = -1;
	}
	free(res);
	free(control);
	return (outcome);
}

static int	cycle_strcpy_tests(void)
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
		if (check_strcpy(arr[index++]) == -1)
			outcome = -1;
	}
	return (outcome);
}

int			test_strcpy(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_strcpy_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
