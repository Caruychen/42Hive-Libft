/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:46:31 by cchen             #+#    #+#             */
/*   Updated: 2021/11/19 16:24:41 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

static int	parse_sign(const char **str)
{
	if (**str == '-' || **str == '+')
		return (1 - 2 * (*(*str)++ == '-'));
	return (1);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	while (is_whitespace(*str))
		++str;
	sign = parse_sign(&str);
	res = 0;
	while (is_numeric(*str))
		res = res * 10 + *str++ - '0';
	return (sign * res);
}
