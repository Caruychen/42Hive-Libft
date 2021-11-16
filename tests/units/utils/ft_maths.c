/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:13:34 by cchen             #+#    #+#             */
/*   Updated: 2021/11/16 10:17:02 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

size_t	get_max(size_t n1, size_t n2)
{
	return (n1 >= n2 ? n1 : n2);
}

size_t	find_max_len(char *s1, char *s2)
{
	return (get_max(strlen(s1), strlen(s2)));
}
