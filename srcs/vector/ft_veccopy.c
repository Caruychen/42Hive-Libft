/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veccopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:21:34 by cchen             #+#    #+#             */
/*   Updated: 2021/12/21 10:30:38 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_veccopy(t_vec *dst, t_vec *src)
{
	int	cpy_bytes;

	if (!dst || !src)
		return (-1);
	if (dst->alloc_size > src->len * src->elem_size)
		cpy_bytes = src->len * src->elem_size;
	else
		cpy_bytes = dst->alloc_size;
	ft_memcpy(dst->memory, src->memory, cpy_bytes);
	return (cpy_bytes);
}
