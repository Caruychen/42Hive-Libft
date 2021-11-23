/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:51:19 by cchen             #+#    #+#             */
/*   Updated: 2021/11/23 11:00:04 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

static int	check_lstnew_results(void const *content, size_t content_size)
{
	t_list	*list = ft_lstnew(content, content_size);
	if (content == NULL)
	{
		if (!(list->content == NULL && list->content_size == 0))
		{
			printf("FAILED: Error in ft_lstnew.\n");
			if (list->content != NULL)
				printf("Expected content: NULL, got non-NULL\n");
			if (list->content_size != 0)
				printf("Expected content_size: 0, got: %zu\n", list->content_size);
			free(list);
			return (-1);
		}
	}
	else if (memcmp(list->content, content, content_size) || list->content_size != content_size)
	{
		printf("FAILED: Error in ft_lstnew.\n");
		free(list);
		return (-1);
	}
	free(list);
	return (0);
}

static int	cycle_lstnew_tests(void)
{
	char	*str = "Hello World";
	int		num = 42;
	int		outcome = 0;

	if (check_lstnew_results(str, sizeof(str)) == -1)
		outcome = -1;
	if (check_lstnew_results(&num, sizeof(num)) == -1)
		outcome = -1;
	if (check_lstnew_results(NULL, 4) == -1)
		outcome = -1;
	if (check_lstnew_results(NULL, 0) == -1)
		outcome = -1;
	return (outcome);
}

int	test_lstnew(void)
{
	int	outcome = 0;

	outcome = cycle_lstnew_tests() || outcome;
	print_outcome(outcome, __func__);
	return (-outcome);
}
