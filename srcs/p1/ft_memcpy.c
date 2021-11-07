/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:54:23 by cchen             #+#    #+#             */
/*   Updated: 2021/11/07 21:50:46 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long		*d_l;
	const unsigned long	*s_l;
	unsigned char		*d_c;
	const unsigned char	*s_c;
	unsigned int		chunks;
	unsigned int		trail;

	if (n == 0 || dst == src)
		return (dst);
	chunks = n / sizeof(dst);
	trail = n % sizeof(dst);
	d_l = (unsigned long *)dst;
	s_l = (const unsigned long *)src;
	d_c = (unsigned char *)dst;
	s_c = (const unsigned char *)src;
	while (chunks--)
	{
		*d_l++ = *s_l++;
		d_c += sizeof(d_l);
		s_c += sizeof(s_l);
	}
	while (trail--)
		*d_c++ = *s_c++;
	return (dst);
}
