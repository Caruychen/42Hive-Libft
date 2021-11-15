/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:18:34 by cchen             #+#    #+#             */
/*   Updated: 2021/11/15 12:40:24 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min_size(size_t src_size, size_t len)
{
	if (src_size > len)
		return (len);
	return (src_size);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	src_size;

	if (len == 0)
		return (dst);
	src_size = ft_strlen(src) + 1;
	dst = ft_memcpy(dst, src, ft_min_size(src_size, len));
	if (src_size < len)
		ft_bzero(dst[src_size], len - src_size);
	return (dst);
}
