/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:05:02 by cchen             #+#    #+#             */
/*   Updated: 2021/11/24 22:56:57 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static void	ft_del(void *content, size_t content_size)
{
	content_size = 0;
	free(content);
}

static void	ft_free_lst(t_list **lst)
{
	if (!*lst)
		return ;
	ft_del((*lst)->content, (*lst)->content_size);
	free(*lst);
}

static int	run_lstdel_test(t_list **l1, t_list **l2, t_list **l3, t_list **l4)
{
	ft_lstdel(l3, &ft_del);
	if (*l3 || *l4)
	{
		printf("FAILED: Error in ft_lstdel.\n");
		if (*l3)
		{
			printf("Did not free link l3, or not properly NULLed\n");
			ft_free_lst(l3);
		}
		if (*l4)
		{
			printf("%p\n", *l3);
			printf("%p\n", *l4);
			printf("Did not free link l4, or not properly NULLed\n");
			ft_free_lst(l4);
		}
		ft_free_lst(l1);
		ft_free_lst(l2);
		return (-1);
	}
	if (!(*l1 && *l2))
	{
		printf("FAILED: Error in ft_lstdel\n");
		if (!*l1)
			printf("Memory of l1 was incorrectly free'd\n");
		if (!*l2)
			printf("Memory of l2 was incorrectly free'd\n");
		ft_free_lst(l1);
		ft_free_lst(l2);
		return (-1);
	}
	ft_free_lst(l1);
	ft_free_lst(l2);
	return (0);
}

static void	initialize_lists(t_list **l1, t_list **l2, t_list **l3, t_list **l4)
{
	char	s1[] = "Hello";
	char	s2[] = "World";
	char	s3[] = "Foo";
	char	s4[] = "Bar";
	
	*l1 = ft_lstnew(s1, sizeof(s1));
	*l2 = ft_lstnew(s2, sizeof(s2));
	*l3 = ft_lstnew(s3, sizeof(s3));
	*l4 = ft_lstnew(s4, sizeof(s4));
	(*l1)->next = *l2;
	(*l2)->next = *l3;
	(*l3)->next = *l4;
}

int	test_lstdel(void)
{
	int	outcome = 0;
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;
	t_list	*l4;

	initialize_lists(&l1, &l2, &l3, &l4);
	outcome = run_lstdel_test(&l1, &l2, &l3, &l4) || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
};
