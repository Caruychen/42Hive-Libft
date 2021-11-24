/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdelarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:17:13 by cchen             #+#    #+#             */
/*   Updated: 2021/11/24 09:17:21 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdelarray(void ***arr)
{
	void	**temp;

	temp = *arr;
	while (*temp)
		ft_memdel(temp++);
	free(*arr);
	*arr = NULL;
}
