/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:08:45 by cchen             #+#    #+#             */
/*   Updated: 2021/11/13 16:11:34 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	iterate_str_arr(char **arr, int (*f)(char *))
{
	int	index = 0;
	int	outcome = 0;

	while (arr[index])
	{
		if (f(arr[index++]) == -1)
			outcome = -1;
	}
	return (outcome);
}
