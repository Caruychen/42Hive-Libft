/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:22:06 by cchen             #+#    #+#             */
/*   Updated: 2021/11/10 22:53:40 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar('-');
		ln = -ln;
	}
	if (ln < 10)
	{
		ft_putchar('0' + ln);
		return ;
	}
	else
		ft_putnbr(ln / 10);
	ft_putnbr(ln % 10);
}
