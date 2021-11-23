/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memccpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:34:37 by cchen             #+#    #+#             */
/*   Updated: 2021/11/23 19:54:37 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static void	ft_putnstr(char *str, size_t n)
{
	while (n--)
		write(1, str++, 1);
	write(1, "\n", 1);
}

static int	test_null(void)
{
	char	*src;
	char	*testDest;
	void	*ret2;

	src = NULL;
	testDest = NULL;
	ret2 = ft_memccpy(testDest, src, '@', 10);
	if (ret2 != NULL || testDest != NULL)
	{
		printf("FAILED: Error at ft_memccpy with test_null\n");
		return (-1);
	}
	return (0);
}

static int	test_chars(char *src, char *controlDest, char *testDest, int c, int length)
{
	void	*ret1;
	void	*ret2;
	int		index;
	long	ret_diff;

	index = 0;
	while (index < length + 1)
	{
		memset(controlDest, 'x', length);
		memset(testDest, 'x', length);
		ret1 = memccpy(controlDest, src, c, index);
		ret2 = ft_memccpy(testDest, src, c, index);
		if (memcmp(controlDest, testDest, length) != 0)
		{
			printf("FAILED: Error at ft_memccpy with test_chars\n");
			printf("Expected:\n");
			ft_putnstr(controlDest, length);
			printf("Got:\n");
			ft_putnstr(controlDest, length);
			return (-1);
		}
		if (ret1 == NULL && ret2 != NULL)
		{
			printf("FAILED: Error at ft_memcpy with test_chars\n");
			printf("Expected ft_memcpy to return NULL pointer, but got: %p\n", ret2);
			return (-1);
		}
		if (ret1)
		{
			ret_diff = ret1 - (void *)controlDest;
			if (ret2 != testDest + ret_diff)
			{
				printf("FAILED: Error at ft_memcpy with test_chars,\n");
				printf("ft_memcpy returned an incorrect address.\n");
				printf("Expected: %p\n", testDest + ret_diff);
				printf("Got	: %p\n", ret2);
				return (-1);
			}
		}
		++index;
	}
	return (0);
}

static int	test_chars_from_src(char *src, char *controlDest, char *testDest, int length)
{
	void	*ret1;
	void	*ret2;
	int		c;
	
	c = src[4];
	bzero(controlDest, length);
	bzero(testDest, length);
	ret1 = memccpy(controlDest, src, c, length);
	ret2 = ft_memccpy(testDest, src, c, length);
	if (memcmp(ret1, ret2, 5) != 0
		|| memcmp(controlDest, testDest, 5) != 0)
	{
		printf("FAILED: Error at ft_memccpy with test_chars_from_src\n");
		printf("%p, %p\n", ret1, ret2);
		printf("%p, %p\n", ret1, ret2);
		printf("%s, %s\n", controlDest, testDest);
		printf("%p, %p\n", controlDest, testDest);
		return (-1);
	}
	return (0);
}

static int	test_ints(int *src, int *controlDest, int *testDest, int c, int length)
{
	void			*ret1;
	void			*ret2;
	unsigned long	index;

	index = 0;
	while (index < sizeof(int) * (length + 1))
	{
		bzero(controlDest, index);
		bzero(testDest, index);
		ret1 = memccpy(controlDest, src, c, index);
		ret2 = ft_memccpy(testDest, src, c, index);
		if (ret1 != ret2 || memcmp(controlDest, testDest, index) != 0)
		{
			printf("FAILED: Error at ft_memccpy with test_ints\n");
			return (-1);
		}
		++index;
	}
	return (0);
}

static int	test_ints_from_src(int *src, int *controlDest, int *testDest, int length)
{
	void	*ret1;
	void	*ret2;
	int		c;
	
	c = src[4];
	bzero(controlDest, sizeof(int) * length);
	bzero(testDest, sizeof(int) * length);
	ret1 = memccpy(controlDest, src, c, sizeof(int) * length);
	ret2 = ft_memccpy(testDest, src, c, sizeof(int) * length);
	if (memcmp(ret1, ret2, sizeof(int) * 5) != 0
		|| memcmp(controlDest, testDest, sizeof(int) * 5) != 0)
	{
		printf("FAILED: Error at ft_memccpy with test_ints_from_src\n");
		return (-1);
	}
	return (0);
}

int	test_memccpy(void)
{
	char	src[11] = "Foo Bar!!!";
	char	controlDest[20] = {0};
	char	testDest[20] = {0};
	int		i_src[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int		i_controlDest[10];
	int		i_testDest[10];
	int		outcome;

	outcome = 0;
	outcome = test_null() || outcome;
	outcome = test_chars(src, controlDest, testDest, '@', 20) || outcome;
	outcome = test_chars(src, controlDest, testDest, 0, 20) || outcome;
	outcome = test_chars(src, controlDest, testDest, 'B', 20) || outcome;
	outcome = test_chars_from_src(src, controlDest, testDest, 20) || outcome;
	outcome = test_ints(i_src, i_controlDest, i_testDest, 127, 10) || outcome;
	outcome = test_ints_from_src(i_src, i_controlDest, i_testDest, 10) || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
