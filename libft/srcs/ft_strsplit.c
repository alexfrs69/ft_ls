/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:14:21 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/15 20:24:38 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int		ft_countwords(char const *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str != c && *str)
		{
			count++;
			while (*str != c && *str)
				str++;
		}
	}
	return (count);
}

static size_t	ft_wordlen(char const *str, char c)
{
	size_t len;

	len = 0;
	while (*str == c && *str)
		str++;
	while (*str != c && *str++)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		words;
	int		wordscount;
	int		i;
	char	**ret;

	if (!s)
		return (NULL);
	wordscount = ft_countwords(s, c);
	if (!(ret = (char**)malloc(sizeof(char*) * wordscount + 1)))
		return (NULL);
	words = 0;
	while (words < wordscount)
	{
		while (*s == c && *s)
			s++;
		if (!(ret[words] = ft_strnew(ft_wordlen(s, c))))
			return (NULL);
		i = 0;
		while (*s != c && *s)
			ret[words][i++] = *s++;
		words++;
	}
	ret[words] = ((void*)0);
	return (ret);
}
