/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:55:41 by cchen             #+#    #+#             */
/*   Updated: 2021/11/10 14:16:20 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	test_putendl_fd(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_str_tests_fd(&ft_putendl_fd) || outcome;
	return (-outcome);
}
