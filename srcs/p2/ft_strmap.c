/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:09:34 by cchen             #+#    #+#             */
/*   Updated: 2021/11/13 15:20:11 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	length;
	char	*res;
	char	*cpy;

	length = ft_strlen(s);
	if (!(res = (char *)malloc(sizeof(*res) * (length + 1)))) 
		return (NULL);
	cpy = res;
	while (length--)
		*cpy++ = f(*s++);
	*cpy = 0;
	return (res);
}
