/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:46:57 by cchen             #+#    #+#             */
/*   Updated: 2021/11/17 11:11:52 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*latest;
	char	ch;

	latest = (char *)0;
	ch = (char)c;
	while (1)
	{
		if (*s == ch)
			latest = (char *)s;
		if (*s == 0)
			return (latest);
		++s;
	}
}
