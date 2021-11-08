/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:36:22 by cchen             #+#    #+#             */
/*   Updated: 2021/11/08 15:13:53 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_putstr(void)
{
	char *s1 = "Hello World";
	char *s2 = "";
	char *s3 = "\n";

	printf("Checking output of ft_putstr\n");
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putstr(s3);
	return (0);
}
