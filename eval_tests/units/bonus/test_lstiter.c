/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:59:49 by cchen             #+#    #+#             */
/*   Updated: 2021/11/25 16:54:54 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static void	ft_set_x(t_list *elem)
{
	memset(elem->content, 'x', elem->content_size);
}

static int	is_all_x(char *s)
{
	while(*s)
	{
		if (*s++ != 'x')
			return (0);
	}
	return (1);
}

static void	ft_del(void *content, size_t content_size)
{
	content_size = 0;
	free(content);
}

static int	check_results(t_list *list)
{
	t_list	*temp = list;
	ft_lstiter(list, ft_set_x);
	while (list)
	{
		if (!is_all_x((char*)list->content))
		{
			printf("FAILED: Error in ft_lstadd.\n");
			printf("Link not modified as expected\n");
			printf("Expected string to be all x, got: %s\n", (char*)list->content);
			ft_lstdel(&temp, ft_del);
			return (-1);
		}
		list = list->next;
	}
	ft_lstdel(&temp, ft_del);
	return (0);
}

static int	cycle_lstiter_test(void)
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
	l1 = ft_lstnew(s1, sizeof(s1));
	l2 = ft_lstnew(s2, sizeof(s2));
	l3 = ft_lstnew(s3, sizeof(s3));
	l4 = ft_lstnew(s4, sizeof(s4));
	ft_lstadd(&begin, l4);
	ft_lstadd(&begin, l3);
	ft_lstadd(&begin, l2);
	ft_lstadd(&begin, l1);
	return (check_results(begin));
}

int	test_lstiter(void)
{
	int	outcome = 0;

	outcome = cycle_lstiter_test() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
