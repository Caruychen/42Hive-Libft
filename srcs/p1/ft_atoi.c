/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:46:31 by cchen             #+#    #+#             */
/*   Updated: 2021/11/23 13:40:54 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define FT_LLONG_MAX 9223372036854775807

static int	parse_sign(const char **str)
{
	if (**str == '-' || **str == '+')
		return (1 - 2 * (*(*str)++ == '-'));
	return (1);
}

static int	parse_numstr(const char *str, int base, int sign)
{
	long long	res;
	long long	cutoff;
	int			cutlim;

	cutoff = FT_LLONG_MAX;
	cutlim = cutoff % base + '0';
	cutoff /= base;
	res = 0;
	while (ft_isdigit(*str))
	{
		if (res > cutoff || (res == cutoff && *str > cutlim))
		{
			res = 0 - (sign > 0);
			break ;
		}
		res = res * 10 + *str++ - '0';
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			res;

	while (ft_iswhitespace(*str))
		++str;
	sign = parse_sign(&str);
	res = parse_numstr(str, 10, sign);
	return (sign * res);
}
