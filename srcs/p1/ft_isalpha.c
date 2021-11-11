/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:34:41 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 11:39:53 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_upper(unsigned char c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	is_lower(unsigned char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isalpha(int c)
{
	unsigned char	u_c;

	u_c = (unsigned char) c;
	return (is_upper(u_c) || is_lower(u_c));
}
