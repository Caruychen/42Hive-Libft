/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:01:07 by cchen             #+#    #+#             */
/*   Updated: 2021/11/18 21:28:01 by cchen            ###   ########.fr       */
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
int		iterate_str_arr(char **arr, int (*f)(char *));
int		iterate_dual_arrays(char **arr1, char **arr2, int length, int (*f)(char *, char *));
int		iterate_chars(const char *str, int (*f)(const char *, int));
size_t	get_max(size_t n1, size_t n2);
size_t	find_max_len(char *s1, char *s2);

// Tests for part 1
int	test_memset(void);
int	test_bzero(void);
int	test_memcpy(void);
int	test_memccpy(void);
int	test_memmove(void);
int	test_memchr(void);
int	test_memcmp(void);
int	test_strlen(void);
int	test_strdup(void);
int	test_strcpy(void);
int	test_strncpy(void);
int	test_strcat(void);
int	test_strncat(void);
int	test_strlcat(void);
int	test_strchr(void);
int	test_strrchr(void);
int	test_strstr(void);
int	test_strnstr(void);
int	test_strcmp(void);
int	test_strncmp(void);
int	test_isalpha(void);
int	test_isdigit(void);
int	test_isalnum(void);
int	test_isascii(void);
int	test_isprint(void);
int	test_toupper(void);
int	test_tolower(void);

// Tests for part 2
int	test_memalloc(void);
int	test_memdel(void);
int	test_strnew(void);
int	test_strdel(void);
int	test_strclr(void);
int	test_striter(void);
int	test_striteri(void);
int	test_strmap(void);
int	test_strmapi(void);
int	test_strequ(void);
int	test_strnequ(void);
int	test_strsub(void);
int	test_strjoin(void);
int	test_putchar(void);
int	test_putstr(void);
int	test_putendl(void);
int	test_putnbr(void);
int	test_putchar_fd(void);
int	test_putstr_fd(void);
int	test_putnbr_fd(void);

#endif
