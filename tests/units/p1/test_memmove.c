/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:33:22 by cchen             #+#    #+#             */
/*   Updated: 2021/11/04 19:59:00 by cchen            ###   ########.fr       */
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
	ret2 = ft_memmove(testDest, src, 10);
	if (ret2 != NULL || testDest != NULL)
	{
		printf("FAILED: Error at ft_memmove with test_null\n");
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
		ret1 = memmove(controlDest, src, index);
		ret2 = ft_memmove(testDest, src, index);
		if (memcmp(ret1, ret2, index) != 0
			|| memcmp(controlDest, testDest, index) != 0)
		{
			printf("FAILED: Error at ft_memmove with test_chars\n");
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
		ret1 = memmove(controlDest, src, index);
		ret2 = ft_memmove(testDest, src, index);
		if (memcmp(ret1, ret2, index) != 0
			|| memcmp(controlDest, testDest, index) != 0)
		{
			printf("FAILED: Error at ft_memmove with test_ints\n");
			return (-1);
		}
		++index;
	}
	return (0);
}

static int	test_overlap(void)
{
	char	s1[] = "abcde";	
	char	s2[] = "abcde";
	void	*ret1;
	void	*ret2;

	ret1 = memmove(s1, s1 + 2, sizeof(char) * 3);
	ret2 = ft_memmove(s2, s2 + 2, sizeof(char) * 3);
	if (memcmp(ret1, ret2, sizeof(char) * 5) != 0
		|| memcmp(s1, s2, sizeof(char) * 5) != 0)
	{
		printf("FAILED: Error at ft_memmove with test_overlap 1\n");
		return (-1);
	}
	char	s3[] = "abcde";
	char	s4[] = "abcde";
	ret1 = memmove(s3 + 2, s3, sizeof(char) * 3);
	ret2 = ft_memmove(s4 + 2, s4, sizeof(char) * 3);
	if (memcmp(ret1, ret2, sizeof(char) * 4) != 0
		|| memcmp(s3, s4, sizeof(char) * 5) != 0)
	{
		printf("%d\n", (int)(*(char*)(ret1 + 3)));
		printf("%d\n", (int)(*(char*)(ret2 + 3)));
		printf("%s\n", s3);
		printf("%s\n", s4);
		/*printf("%p\n", ret1);
		printf("%p\n", s3);
		printf("%p\n", ret2);
		printf("%p\n", s4);*/
		printf("FAILED: Error at ft_memmove with test_overlap 2\n");
		return (-1);
	}
	return (0);
}

int	test_memmove(void)
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
	outcome = test_overlap() || outcome;
	return (-outcome);
}
