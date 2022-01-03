/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:06:53 by cchen             #+#    #+#             */
/*   Updated: 2021/11/15 10:36:46 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static char	ft_mapi_fn(unsigned int index, char c)
{
	if (index % 2 == 0)
		return (++c);
	return (c);
}

static int	run_strmapi_check(char *s, char *t)
{
	char	*res;
	size_t	length = strlen(s);
	int		outcome = 0;

	res = ft_strmapi(s, ft_mapi_fn);
	if (strcmp(res, t) != 0)
	{
		printf("FAILED: Error in strmapi.\n");
		printf("Expected: %s, Got %s\n", t, res);
		outcome = -1;
	}
	if (res[length] != '\0')
	{
		printf("FAILED: Error in strmapi.\n");
		printf("Resulting string not null terminated\n");
		outcome = -1;
	}
	free(res);	
	res = NULL;
	return (outcome);
}

static int	cycle_strmapi_tests(void)
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
		if (run_strmapi_check(arr_s[index], arr_t[index]) == -1)
			outcome = -1;
		++index;
	}
	return (outcome);
}

int			test_strmapi(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_strmapi_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
