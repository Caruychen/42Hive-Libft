/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:11:26 by cchen             #+#    #+#             */
/*   Updated: 2021/11/05 17:47:08 by cchen            ###   ########.fr       */
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

static int	test_overlap(void)
{
	char	s1[] = "abcde";	
	char	s2[] = "abcde";
	void	*ret1;
	void	*ret2;

	ret1 = memcpy(s1, s1 + 2, sizeof(char) * 3);
	ret2 = ft_memcpy(s2, s2 + 2, sizeof(char) * 3);
	if (memcmp(ret1, ret2, sizeof(char) * 5) != 0
		|| memcmp(s1, s2, sizeof(char) * 5) != 0)
	{
		printf("FAILED: Error at ft_memcpy with test_overlap 1\n");
		return (-1);
	}
	char	s3[] = "abcde";
	char	s4[] = "abcde";
	ret1 = memcpy(s3 + 2, s3, sizeof(char) * 3);
	ret2 = ft_memcpy(s4 + 2, s4, sizeof(char) * 3);
	if (memcmp(ret1, ret2, sizeof(char) * 4) != 0
		|| memcmp(s3, s4, sizeof(char) * 5) != 0)
	{
		printf("%d\n", (int)(*(char*)(ret1 + 3)));
		printf("%d\n", (int)(*(char*)(ret2 + 3)));
		printf("%p\n", ret1);
		printf("%p\n", s3);
		printf("%p\n", ret2);
		printf("%p\n", s4);
		printf("FAILED: Error at ft_memcpy with test_overlap 2\n");
		return (-1);
	}
	return (0);
}
/*
static void	demo_memcpy(void)
{
	char s1[] = "abcde";
	char s2[] = "abcde";
	void *ret1 = memcpy(s1 + 2, s1, sizeof(char) * 3);
	void *ret2 = memmove(s2 + 2, s2, sizeof(char) * 3);
	printf("Original string: abcde\n");
	printf("Source after memcpy: %s\n", s1);
	printf("Source of memmove: %s\n", s2);
	printf("Return from memcpy: %s\n", ret1);
	printf("Return from memmove: %s\n", ret2);
}
*/
static void	demo_memcpy(void)
{
	char i1[] = "012345";
//	char i2[] = "0123456789";
//	char i3[] = "0123456789";

	printf("original 1: %s\n", i1);
//	printf("original 2: %s\n", i2);
//	printf("original 3: %s\n", i3);
	memcpy(i1 + 2, i1, 5);
//	ft_memcpy(i2 + 2, i2, 9);
//	memmove(i3 + 2, i3, 9);
	printf("res: %p, %s\n", i1, i1);
//	printf("res: %p, %s\n", i2, i2);
//	printf("res: %p, %s\n", i3, i3);
//	printf("%ld, %ld, %ld", i1 - i2, i2 - i3, i3 - i3);
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
	outcome = test_overlap() || outcome;
	demo_memcpy();
	return (-outcome);
}	
