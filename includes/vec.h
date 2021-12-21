/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:01:19 by cchen             #+#    #+#             */
/*   Updated: 2021/12/21 11:36:13 by cchen            ###   ########.fr       */
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
int		ft_vecfrom(t_vec *dst, void *src, size_t len, size_t elem_size);
int		ft_veccopy(t_vec *dst, t_vec *src);
int		ft_vecresize(t_vec *src, size_t target_size);

#endif
