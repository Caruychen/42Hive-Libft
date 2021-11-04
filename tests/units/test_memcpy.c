/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:11:26 by cchen             #+#    #+#             */
/*   Updated: 2021/11/04 13:05:46 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	test_null(void)
{
	char	*src;
	char	*testDest;
	void	*ret2;

	src = NULL;
	testDest = NULL;
	ret2 = ft_memcpy(testDest, src, 10);
	if (ret2 != NULL || testDest != NULL)
	{
		printf("FAILED: Error at ft_memcpy with test_null\n");
		return (-1);
	}
	return (0);
}

static int	test_chars(char *src, char *controlDest, char *testDest, int length)
{
	void	*ret1;
	void	*ret2;
	int		index;

	index = 0;
	while (index < length + 1)
	{
		bzero(controlDest, index);
		bzero(testDest, index);
		ret1 = memcpy(controlDest, src, index);
		ret2 = ft_memcpy(testDest, src, index);
		if (memcmp(ret1, ret2, index) != 0
			|| memcmp(controlDest, testDest, index) != 0)
		{
			printf("FAILED: Error at ft_memcpy with test_chars\n");
			return (-1);
		}
		++index;
	}
	return (0);
}

static int	test_ints(int *src, int *controlDest, int *testDest, int length)
{
	void				*ret1;
	void				*ret2;
	unsigned long		index;

	index = 0;
	while (index < sizeof(int) * (length + 1))
	{
		bzero(controlDest, index);
		bzero(testDest, index);
		ret1 = memcpy(controlDest, src, index);
		ret2 = ft_memcpy(testDest, src, index);
		if (memcmp(ret1, ret2, index) != 0
			|| memcmp(controlDest, testDest, index) != 0)
		{
			printf("FAILED: Error at ft_memcpy with test_ints\n");
			return (-1);
		}
		++index;
	}
	return (0);
}

int	test_memcpy(void)
{
	char	src[11] = "Foo Bar!!!";
	char	controlDest[10] = {'\0'};
	char	testDest[10] = {'\0'};
	int		i_src[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int		i_controlDest[10];
	int		i_testDest[10];
	int		outcome;

	outcome = 0;
	outcome = test_null() || outcome;
	outcome = test_chars(src, controlDest, testDest, 10) || outcome;
	outcome = test_ints(i_src, i_controlDest, i_testDest, 10) || outcome;
	return (-outcome);
}	
