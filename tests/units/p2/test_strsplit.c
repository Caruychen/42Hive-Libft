/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:02:04 by cchen             #+#    #+#             */
/*   Updated: 2021/11/19 13:28:34 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	cycle_strplit_test(void)
{
	char *s1 = { "*hello*fellow***students*", "hello", "fellow", "students" , 0 };
	char *s2 = { "foo", "foo" };
	char *s3 = { "f", "f" };
	char *s4 = "";
	char *s5 = "*";
}

int	test_strsplit(void)
{
	int	outcome = 0;

	outcome = cycle_strsplit_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
