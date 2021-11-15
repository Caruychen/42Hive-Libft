/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:03:10 by cchen             #+#    #+#             */
/*   Updated: 2021/11/15 11:07:12 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	length;

	length = ft_strlen(s1);
	new = ft_strnew(length);
	if (!new)
		return (NULL);
	new = ft_memcpy(new, s1, length + 1);
	return (new);
}
