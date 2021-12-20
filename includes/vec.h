/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:01:19 by cchen             #+#    #+#             */
/*   Updated: 2021/12/20 15:18:17 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <string.h>

typedef struct s_vec
{
	void			*memory;
	size_t			elem_size;
	size_t			alloc_size;
	size_t			len;
}		t_vec;

int		ft_vecnew(t_vec *dst, size_t init_alloc, size_t elem_size);
void	ft_vecfree(t_vec *src);

#endif
