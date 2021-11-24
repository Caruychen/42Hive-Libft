/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:54:44 by cchen             #+#    #+#             */
/*   Updated: 2021/11/24 09:12:25 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delarray(void ***arr)
{
	void	**temp;

	temp = *arr;
	while (*temp)
		ft_memdel(temp++);
	free(*arr);
	*arr = NULL;
}
