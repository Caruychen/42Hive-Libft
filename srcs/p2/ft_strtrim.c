/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:35:37 by cchen             #+#    #+#             */
/*   Updated: 2021/11/18 22:21:10 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static char	*seek_end(char const *s)
{
	char	*end;

	end = (char *)s;
	while (*s)
	{
		if (!is_whitespace(*s))
			end = (char *)s;
		++s;
	}
	return (end);
}

static size_t	get_length(char const *s)
{
	size_t	length;

	length = seek_end(s) - s + 1;
	return (length);
}

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	length;

	while (is_whitespace(*s))
		++s;
	length = get_length(s);
	str = (char *)malloc(sizeof(*str) * (length + 1));	
	ft_memcpy(str, s, length);
	str[length] = 0;
	return (str);
}
