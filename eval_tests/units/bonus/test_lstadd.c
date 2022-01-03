/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:11:22 by cchen             #+#    #+#             */
/*   Updated: 2021/11/25 15:47:33 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static void	ft_del(void *content, size_t content_size)
{
	content_size = 0;
	free(content);
}

static int	check_results(t_list *begin, char **exparr)
{
	t_list	*temp = begin;
	while (begin)
	{
		if (strcmp((char*)begin->content, *exparr++))
		{
			printf("FAILED: Error in ft_lstadd.\n");
			printf("Mismatch in link\nExpected: %s, got: %s\n", \
				(char *)begin->content, *(exparr-1));
			ft_lstdel(&temp, ft_del);
			return (-1);
		}
		begin = begin->next;
	}
	ft_lstdel(&temp, ft_del);
	return (0);
}

static int	cycle_lstadd_test(void)
{
	t_list	*begin = NULL;;
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;
	t_list	*l4;
	char	s1[] = "Hello";
	char	s2[] = "World";
	char	s3[] = "Foo";
	char	s4[] = "Bar";
	char	*exparr[] = {
		"Hello", "World", "Foo", "Bar" };
	l1 = ft_lstnew(s1, sizeof(s1));
	l2 = ft_lstnew(s2, sizeof(s2));
	l3 = ft_lstnew(s3, sizeof(s3));
	l4 = ft_lstnew(s4, sizeof(s4));
	ft_lstadd(&begin, l4);
	ft_lstadd(&begin, l3);
	ft_lstadd(&begin, l2);
	ft_lstadd(&begin, l1);
	return (check_results(begin, exparr));
}

int	test_lstadd(void)
{
	int	outcome = 0;

	outcome = cycle_lstadd_test() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
