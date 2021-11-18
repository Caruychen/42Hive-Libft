/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:19:52 by cchen             #+#    #+#             */
/*   Updated: 2021/11/18 16:03:36 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	traverse_dst(char **d, size_t dstsize)
{
	char	*start;

	start = *d;
	while (dstsize-- && **d)
		++(*d);
	return (*d - start);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*d;
	char	*s;
	size_t	bufferlen;
	size_t	dlen;

	d = (char *)dst;
	s = (char *)src;
	dlen = traverse_dst(&d, dstsize);
	bufferlen = dstsize - dlen;
	if (bufferlen == 0)
		return (dlen + ft_strlen(src));
	while (*s)
	{
		if (bufferlen != 1)
		{
			*d++ = *s;
			--bufferlen;
		}
		++s;
	}
	*d = 0;
	return (dlen + (s - src));
}
