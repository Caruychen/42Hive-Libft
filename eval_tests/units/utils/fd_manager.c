/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:19:34 by cchen             #+#    #+#             */
/*   Updated: 2021/11/11 11:20:29 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	init_file(int *fd)
{
	if ((*fd = open("temp", O_CREAT|O_TRUNC|O_RDWR, 0666)) == -1)
	{
		fprintf(stderr, "Cannot open temp file\n");
		exit (1);
	}
}
