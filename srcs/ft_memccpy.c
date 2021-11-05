/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:08:09 by cchen             #+#    #+#             */
/*   Updated: 2021/11/05 13:53:32 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void			*ptr;
	unsigned	int c_len;

	if (n == 0 || dst == src)
		return (NULL);
	ptr = ft_memchr(src, c, n);
	if (ptr != NULL)
	{
		c_len = ptr - src + 1;
		return (ft_memcpy(dst, src, c_len) + c_len);
	}
	ft_memcpy(dst, src, n);
	return (NULL);
}
