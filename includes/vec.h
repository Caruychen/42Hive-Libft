/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:01:19 by cchen             #+#    #+#             */
/*   Updated: 2021/12/20 12:40:41 by cchen            ###   ########.fr       */
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

int	vec_new(t_vec *src, size_t len, size_t elem_size);
void	vec_free(t_vec *src);

#endif
