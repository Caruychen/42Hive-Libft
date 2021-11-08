/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:54:23 by cchen             #+#    #+#             */
/*   Updated: 2021/11/08 09:29:12 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy_long(unsigned char **dst, const unsigned char **src, size_t n)
{
	unsigned long		*d;
	const unsigned long	*s;

	d = (unsigned long *)*dst;
	s = (const unsigned long *)*src;
	*dst += n * sizeof(long);
	*src += n * sizeof(long);
	while (n--)
		*d++ = *s++;
}

static void	ft_copy_trail(unsigned char **dst, const unsigned char **src, size_t n)
{
	unsigned int	trail_4bytes;
	unsigned int	trail_2bytes;
	unsigned int	trail;

	trail_4bytes = n / sizeof(int);
	trail_2bytes = n % sizeof(int);
	trail = n % sizeof(short);
	while (trail_4bytes--)
		*(*(unsigned int**)dst)++ = *(*(const unsigned int **)src)++;
	while (trail_2bytes--)
		*(*(unsigned short**)dst)++ = *(*(const unsigned short **)src)++;
	while (trail--)
		*(*dst)++ = *(*src)++;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d_c;
	const unsigned char	*s_c;
	unsigned int		chunks;
	unsigned int		trail;

	if (n == 0 || dst == src)
		return (dst);
	d_c = (unsigned char *)dst;
	s_c = (const unsigned char *)src;
	chunks = n / sizeof(long);
	trail = n % sizeof(long);
	if (chunks)
		ft_copy_long(&d_c, &s_c, chunks);
	/*while (trail--)
		*d_c++ = *s_c++;
	*/
	ft_copy_trail(&d_c, &s_c, trail);
	return (dst);
}
