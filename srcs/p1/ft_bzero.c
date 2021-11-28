/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:36:15 by cchen             #+#    #+#             */
/*   Updated: 2021/11/28 10:37:11 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_zero_chunks(void **s, size_t n)
{
	unsigned long	*str;

	str = (unsigned long *)*s;
	*s += n * sizeof(long);
	while (n--)
		*str++ = 0;
}

static void	ft_zero_trail(void **s, size_t n)
{
	unsigned int	chunk;
	unsigned int	trail;

	chunk = n / sizeof(int);
	trail = n % sizeof(int);
	if (chunk)
		*(*(unsigned int **)s)++ = 0;
	if (trail / sizeof(short))
		*(*(unsigned short **)s)++ = 0;
	if (n % sizeof(short))
		*(*(unsigned char **)s)++ = 0;
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	chunks;
	unsigned int	trail;

	if (n == 0)
		return ;
	chunks = n / sizeof(long);
	trail = n % sizeof(long);
	if (chunks)
		ft_zero_chunks(&s, chunks);
	ft_zero_trail(&s, trail);
}
