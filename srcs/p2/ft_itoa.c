/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:55:29 by cchen             #+#    #+#             */
/*   Updated: 2021/11/21 12:51:08 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(int n)
{
	if (n / 10 == 0)
		return (1 + (n < 0));
	return (1 + get_length(n / 10));
}

static void	setnbr(int n, char *str, size_t len)
{
	long int	ln;
	size_t		first;

	ln = n;
	first = 0;
	if (ln < 0)
	{
		*str = '-';
		ln = -ln;
		++first;
	}
	while (len-- > first)
	{
		str[len] = ln % 10 + '0';
		ln /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = get_length(n);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	setnbr(n, str, len);
	str[len] = 0;
	return (str);
}
