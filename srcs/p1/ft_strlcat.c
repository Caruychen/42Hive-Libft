/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:19:52 by cchen             #+#    #+#             */
/*   Updated: 2021/11/18 14:35:44 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	gap_n;
	char	*d;
	char	*s;
	size_t	dlen;

	d = (char *)dst;
	s = (char *)src;
	gap_n = dstsize;
	while (gap_n-- && *d)
		++d;
	dlen = d - dst;
	gap_n = dstsize - dlen;
	if (gap_n == 0)
		return (dlen + ft_strlen(src));
	while (*s)
	{
		if (gap_n != 1)
		{
			*d++ = *s;
			--gap_n;
		}
		++s;
	}
	*d = 0;
	return (dlen + (s - src));
}
