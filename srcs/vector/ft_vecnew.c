/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:53:58 by cchen             #+#    #+#             */
/*   Updated: 2021/12/20 15:12:40 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	vec_new(t_vec *dst, size_t init_alloc, size_t elem_size)
{
	if (!dst || init_alloc == 0 || elem_size == 0)
		return (-1);
	dst->alloc_size = init_alloc * elem_size;
	dst->elem_size = elem_size;
	dst->len = 0;
	dst->memory = malloc(dst->alloc_size);
	if (!dst->memory)
	{
		dst->alloc_size = 0;
		dst->elem_size = 0;
		return (-1);
	}
	return (dst->alloc_size);
}
