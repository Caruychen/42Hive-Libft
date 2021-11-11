/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:01:07 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 17:10:52 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTFT_H
# define TESTFT_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include "libft.h"

// Utilities
int		test_char_is(const char c, const char *f_name, int (*ft_fptr)(int c), int (*fptr)(int c));
int		cycle_char_is_tests(const char *f_name, int (*ft_fptr)(int c), int (*fptr)(int c));
void	init_redirect(int *file_desc, int *copy_out);
void	reset_output(int *copy_out);
void	fr_clean_up(FILE *file, char *res);
void	init_file(int *fd);
void	print_outcome(int outcome, const char *ft_name);

// Tests for part 1
int	test_memset(void);
int	test_bzero(void);
int	test_memcpy(void);
int	test_memccpy(void);
int	test_memmove(void);
int	test_memchr(void);
int	test_memcmp(void);
int	test_strlen(void);
int	test_isalpha(void);
int	test_isdigit(void);
int	test_isalnum(void);
int	test_isascii(void);

// Tests for part 2
int	test_putchar(void);
int	test_putstr(void);
int	test_putendl(void);
int	test_putnbr(void);
int	test_putchar_fd(void);
int	test_putstr_fd(void);
int	test_putnbr_fd(void);

#endif
