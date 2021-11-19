/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:55:29 by cchen             #+#    #+#             */
/*   Updated: 2021/11/19 16:37:37 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static void	setnbr(int n, char *str, size_t len)
{
	long int	ln;

	ln = n;
	if (ln < 0)
	{
		*str = '-';
		--len;
		ln = -ln;
	}
	while (len--)
	{

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
	str[len] = 0;
