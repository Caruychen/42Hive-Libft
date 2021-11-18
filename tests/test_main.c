/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:48:24 by cchen             #+#    #+#             */
/*   Updated: 2021/11/18 15:02:38 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

int	ft_run_tests(void)
{
	int	(*ft_ptr_arr1[])(void) = {
		test_memset,
		test_bzero,
		test_memcpy,
		test_memccpy,
		test_memmove,
		test_memchr,
		test_memcmp,
		test_strlen,
		test_strdup,
		test_strcpy,
		test_strncpy,
		test_strcat,
		test_strncat,
		test_strlcat,
		test_strchr,
		test_strrchr,
		test_strstr,
		test_strnstr,
		test_strcmp,
		test_strncmp,
		test_isalpha,
		test_isdigit,
		test_isalnum,
		test_isascii,
		test_isprint,
		test_toupper,
		test_tolower,
		0};
	int	(*ft_ptr_arr2[])(void) = {
		test_memalloc,
		test_memdel,
		test_strnew,
		test_strdel,
		test_strclr,
		test_striter,
		test_striteri,
		test_strmap,
		test_strmapi,
		test_strequ,
		test_strnequ,
		test_putchar,
		test_putstr,
		test_putendl,
		test_putnbr,
		test_putchar_fd,
		test_putstr_fd,
		test_putnbr_fd,
		0};
	int	index;

	index = 0;
	while (ft_ptr_arr1[index])
		ft_ptr_arr1[index++]();
	printf("PART 1 TESTS OK!\n");
	index = 0;
	while (ft_ptr_arr2[index])
		ft_ptr_arr2[index++]();
	printf("PART 2 TESTS OK!\n");
	return (0);
}

int	main(void)
{
	return (ft_run_tests());
}
