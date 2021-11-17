/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:04:06 by cchen             #+#    #+#             */
/*   Updated: 2021/11/17 22:15:44 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*substring;
	char	*haystack_p;

	if (*needle == 0)
		return ((char *)haystack);
	substring = (char *)needle;
	while (*haystack)
	{
		if (*haystack != *substring)
		{
			++haystack;
			continue ;
		}
		haystack_p = (char *)haystack;
		while (1)
		{
			if (*substring == 0)
				return ((char *)haystack);
			if (*haystack_p++ != *substring++)
				break ;
		}
		++haystack;
		substring = (char *)needle;
	}
	return (NULL);
}	
