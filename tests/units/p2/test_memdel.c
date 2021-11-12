/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:27:49 by cchen             #+#    #+#             */
/*   Updated: 2021/11/12 13:50:26 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	isnull(void *mem)
{
	return (mem == NULL);
}

static int	cycle_memdel_tests(const char *f_name, void (*ft_fptr)(void **ap))
{
	int		size = 100;
	char	*mem1 = (char *)malloc(sizeof(char) * size);
	int		*mem2 = (int *)malloc(sizeof(int) * size);
	void	*mem3 = malloc(size);
	void	*mem4 = NULL;

	ft_fptr((void **)&mem1);
	ft_fptr((void **)&mem2);
	ft_fptr(&mem3);
	ft_fptr(&mem4);

	if (!(isnull(mem1) && isnull(mem2) && isnull(mem3) && isnull(mem4)))
	{
		printf("FAILED: Error in %s, found a non null address.\n", f_name);
		printf("mem1: %p\nmem2: %p\nmem3: %p\nmem4: %p\n", mem1, mem2, mem3, mem4);
		return (-1);
	}
	return (0);
}

int			test_memdel(void)
{
	int	outcome;

	outcome = 0;
	outcome = cycle_memdel_tests("ft_memdel", ft_memdel) || outcome;
	print_outcome(outcome, __func__);
	return (outcome);
}
