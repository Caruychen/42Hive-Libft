/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feedback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:00:08 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 17:11:23 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	red(void)
{
	printf("\033[1;31m");
}

void	green(void)
{
	printf("\033[0;32m");
}

void	reset(void)
{
	printf("\033[0m");
}

void	print_outcome(int outcome, const char *ft_name)
{
	char *res = "OK";

	green();
	if (outcome == -1)
	{
		res = "NOT OK! D:";
		red();
	}
	printf("%s result:	%s\n", ft_name, res);
	reset();
}
