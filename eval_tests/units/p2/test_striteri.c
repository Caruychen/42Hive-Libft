/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:32:36 by cchen             #+#    #+#             */
/*   Updated: 2021/11/13 15:00:59 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static void	ft_iteri(unsigned int index, char *s)
{
	if (index % 2 == 0)
		(*s)++;	
}

static int	run_striteri_check(char *s, char *t)
{
	ft_striteri(s, ft_iteri);
	if (strcmp(s, t) != 0)
	{
		printf("FAILED: Error in striteri.\n");
		printf("Expected: %s, Got %s\n", t, s);
		return (-1);
	}
	return (0);
}

static int	cycle_striteri_tests(void)
{
	char 	s1[] = "foo bar";
	char 	s2[] = "Hello World";
	char 	t1[] = "gop cas";
	char 	t2[] = "Iemlp Xosle";
	char 	*arr_s[] = { s1, s2, 0 };
	char 	*arr_t[] = { t1, t2, 0 };
	int	index = 0;
	int	outcome = 0;

	while (arr_s[index])
	{
		if (run_striteri_check(arr_s[index], arr_t[index]) == -1)
			outcome = -1;
		++index;
	}
	return (outcome);
}

int	test_striteri(void)
{
	int outcome;

	outcome = 0;
	outcome = cycle_striteri_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
