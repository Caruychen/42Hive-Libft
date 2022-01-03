/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:13:35 by cchen             #+#    #+#             */
/*   Updated: 2021/11/23 13:23:24 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static void	ft_del(void	*content, size_t content_size)
{
	content_size = 0;
	free(content);
}

static void	ft_free_lst(t_list **lst)
{
	ft_del((*lst)->content, (*lst)->content_size);
	free(*lst);
}

static int	run_lstdelone_test(t_list **l1, t_list **l2, t_list **l3, t_list **l4)
{
	ft_lstdelone(l2, &ft_del);
	if (*l2)
	{
		printf("FAILED: Error in ft_lstdelone.\n");
		printf("Did not free list memory of l2\n");
		ft_free_lst(l1);
		ft_free_lst(l2);
		ft_free_lst(l3);
		ft_free_lst(l4);
		return (-1);
	}
	if (!(*l1 && *l3 && *l4))
	{
		printf("FAILED: Error in ft_lstdelone.\n");
		if (!*l1)
			printf("Memory of l1 was incorrectly free'd\n");
		if (!*l3)
			printf("Memory of l3 was incorrectly free'd\n");
		if (!*l4)
			printf("Memory of l4 was incorrectly free'd\n");
		if (*l1)
			ft_free_lst(l1);
		if (*l3)
			ft_free_lst(l3);
		if (*l4)
			ft_free_lst(l4);
		return (-1);
	}
	ft_free_lst(l1);
	ft_free_lst(l3);
	ft_free_lst(l4);
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

int	test_lstdelone(void)
{
	int	outcome = 0;
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;
	t_list	*l4;

	initialize_lists(&l1, &l2, &l3, &l4);
	outcome = run_lstdelone_test(&l1, &l2, &l3, &l4) || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
