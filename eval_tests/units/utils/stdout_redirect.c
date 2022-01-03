/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:22:45 by cchen             #+#    #+#             */
/*   Updated: 2021/11/10 10:46:44 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testft.h"

void	init_redirect(int *file_desc, int *copy_out)
{
	if ((*file_desc = open("temp", O_RDWR|O_CREAT|O_TRUNC, 0666)) == -1)
	{
		printf("Could not open temp file.\n");
		exit (1);
	}
	*copy_out = dup(fileno(stdout));
	dup2(*file_desc, fileno(stdout));
}

void	reset_output(int *copy_out)
{
	dup2(*copy_out, fileno(stdout));
	close(*copy_out);
}

void	fr_clean_up(FILE *file, char *res)
{
	if (fclose(file))
	{
		fprintf(stderr, "Cannot close temp file\n");
		exit (1);
	}
	if (remove("temp"))
	{
		fprintf(stderr, "Cannot remove temp file\n");
		exit (1);
	}
	free(res);
}
