/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:46:57 by cchen             #+#    #+#             */
/*   Updated: 2021/11/17 11:04:44 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*latest;
	char	ch;

	latest = (char *)0;
	while (1)
	{
		ch = *s;
		if (ch == c)
			latest = (char *)s;
		if (ch == 0)
			return (latest);
		++s;
	}
	return (latest);
}
