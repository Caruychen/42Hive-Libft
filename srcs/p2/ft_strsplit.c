/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:55:49 by cchen             #+#    #+#             */
/*   Updated: 2021/11/24 09:25:21 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (in_word && *s == c)
			in_word = 0;
		if (!in_word && *s != c)
		{
			++count;
			in_word = 1;
		}
		++s;
	}
	return (count);
}

static void	seek_word(char const **s, char c)
{
	while (**s == c)
		++(*s);
}

static size_t	get_word_length(char const *s, char c)
{
	size_t	length;

	length = 0;
	while (*s && *s != c)
	{
		++length;
		++s;
	}
	return (length);
}

static char const	*copy_word(char **arr, char const *s, char c)
{
	size_t	length;

	length = get_word_length(s, c);
	*arr = ft_strsub(s, 0, length);
	return (s + length);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**s_arr;
	char	**temp;
	size_t	words;

	words = count_words(s, c);
	s_arr = (char **)malloc(sizeof(*s_arr) * (words + 1));
	if (!s_arr)
		return (NULL);
	s_arr[words] = 0;
	temp = s_arr;
	while (words--)
	{
		seek_word(&s, c);
		s = copy_word(temp, s, c);
		if (*temp++ == NULL)
		{
			ft_strdelarray(&s_arr);
			return (NULL);
		}
	}
	return (s_arr);
}
