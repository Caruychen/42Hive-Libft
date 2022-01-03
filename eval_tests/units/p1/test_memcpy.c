/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:11:26 by cchen             #+#    #+#             */
/*   Updated: 2021/12/09 13:50:04 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static void	ft_putnstr(char *str, size_t n)
{
	while (n--)
	{
		ft_putchar(*str++);
		if (*str == 0)
			return ;
	}
}

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
			printf("FAILED: Error at ft_memcpy with test_chars, index: %d\n", index);
			ft_putnstr(controlDest, index + 1);
			ft_putchar('\n');
			ft_putnstr(testDest, index + 1);
			ft_putchar('\n');
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

/*
static int	test_overlap(void)
{
	char	s1[] = "12345678";
	char	s2[] = "123456781";
	char	s3[] = "1234567812";
	char	s4[] = "12345678123";
	char	s5[] = "123456781234";
	char	s6[] = "1234567812345";
	char	s7[] = "12345678123456";
	char	s8[] = "123456781234567";
	char	t1[] = "12345678";
	char	t2[] = "123456781";
	char	t3[] = "1234567812";
	char	t4[] = "12345678123";
	char	t5[] = "123456781234";
	char	t6[] = "1234567812345";
	char	t7[] = "12345678123456";
	char	t8[] = "123456781234567";

	printf("%s\n", s1);
	memcpy(s1+ 2, s1, 7);
	ft_memcpy(t1+ 2, t1, 7);
	ft_putnstr(s1, 9);
	ft_putchar('\n');
	ft_putnstr(t1, 9);
	ft_putchar('\n');

	printf("%s\n", s2);
	memcpy(s2+ 2, s2, 8);
	ft_memcpy(t2+ 2, t2, 8);
	ft_putnstr(s2, 10);
	ft_putchar('\n');
	ft_putnstr(t2, 10);
	ft_putchar('\n');

	printf("%s\n", s3);
	memcpy(s3+ 2, s3, 9);
	ft_memcpy(t3+ 2, t3, 9);
	ft_putnstr(s3, 11);
	ft_putchar('\n');
	ft_putnstr(t3, 11);
	ft_putchar('\n');

	printf("%s\n", s4);
	memcpy(s4+ 2, s4, 10);
	ft_memcpy(t4+ 2, t4, 10);
	ft_putnstr(s4, 12);
	ft_putchar('\n');
	ft_putnstr(t4, 12);
	ft_putchar('\n');

	printf("%s\n", s5);
	memcpy(s5+ 2, s5, 11);
	ft_memcpy(t5+ 2, t5, 11);
	ft_putnstr(s5, 13);
	ft_putchar('\n');
	ft_putnstr(t5, 13);
	ft_putchar('\n');

	printf("%s\n", s6);
	memcpy(s6+ 2, s6, 12);
	ft_memcpy(t6+ 2, t6, 12);
	ft_putnstr(s6, 14);
	ft_putchar('\n');
	ft_putnstr(t6, 14);
	ft_putchar('\n');

	printf("%s\n", s7);
	memcpy(s7+ 2, s7, 13);
	ft_memcpy(t7+ 2, t7, 13);
	ft_putnstr(s7, 15);
	ft_putchar('\n');
	ft_putnstr(t7, 15);
	ft_putchar('\n');

	printf("%s\n", s8);
	memcpy(s8+ 2, s8, 14);
	ft_memcpy(t8+ 2, t8, 14);
	ft_putnstr(s8, 16);
	ft_putchar('\n');
	ft_putnstr(t8, 16);
	ft_putchar('\n');

	return (0);
}
*/
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
	//outcome = test_overlap() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}	
