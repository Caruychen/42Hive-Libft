/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:28:11 by cchen             #+#    #+#             */
/*   Updated: 2021/11/12 15:34:55 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	isnull(void *mem)
{
	return (mem == NULL);
}

static int	cycle_strdel_tests(const char *f_name, void (*ft_fptr)(char **as))
{
	int		size = 100;
	char	*mem1 = (char *)malloc(sizeof(char) * size);
	int		*mem2 = (int *)malloc(sizeof(int) * size);
	void	*mem3 = malloc(size);
	void	*mem4 = NULL;

	ft_fptr(&mem1);
	ft_fptr((char **)&mem2);
	ft_fptr((char **)&mem3);
	ft_fptr((char **)&mem4);

	if (!(isnull(mem1) && isnull(mem2) && isnull(mem3) && isnull(mem4)))
	{
		printf("FAILED: Error in %s, found a non null address.\n", f_name);
		printf("mem1: %p\nmem2: %p\nmem3: %p\nmem4: %p\n", mem1, mem2, mem3, mem4);
		return (-1);
	}
	return (0);
}

int			test_strdel(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_strdel_tests("ft_strdel", ft_strdel) || outcome;
	print_outcome(outcome, __func__);
	return (outcome);
}
