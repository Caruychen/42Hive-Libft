/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:23:31 by cchen             #+#    #+#             */
/*   Updated: 2021/11/04 19:56:53 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (len == 0 || dst == src)
		return (dst);
	d = (char *)dst;
	s = (const char *)src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = (char *)dst + (len - 1);
		s = (const char *)src + (len - 1);
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}	
