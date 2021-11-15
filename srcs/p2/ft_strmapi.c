/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:38:50 by cchen             #+#    #+#             */
/*   Updated: 2021/11/15 10:32:29 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_mapi(char *res, char const *s, char (*f)(unsigned int, char),
		size_t size)
{
	size_t	index;

	index = 0;
	while (size--)
		*res++ = f(index++, *s++);
	*res = 0;
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*res;

	if (!s)
		return (NULL);
	size = sizeof(*res) * (ft_strlen(s) + 1);
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	ft_mapi(res, s, f, size - 1);
	return (res);
}
