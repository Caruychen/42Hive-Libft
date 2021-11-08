/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:01:07 by cchen             #+#    #+#             */
/*   Updated: 2021/11/08 13:06:35 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTFT_H
# define TESTFT_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

int	test_memset(void);
int	test_bzero(void);
int	test_memcpy(void);
int	test_memccpy(void);
int	test_memmove(void);
int	test_memchr(void);
int	test_memcmp(void);
int	test_strlen(void);
int	test_putchar(void);
int	test_putstr(void);
int	test_putchar_fd(void);

#endif
