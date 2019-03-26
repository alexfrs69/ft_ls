/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:35:47 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/10 23:18:33 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*tmpsrc;
	char		*tmpdst;
	size_t		dsize;
	size_t		length;

	tmpsrc = src;
	tmpdst = dst;
	length = size;
	while (length-- && *tmpdst)
		tmpdst++;
	dsize = tmpdst - dst;
	length = size - dsize;
	if (!length)
		return (dsize + ft_strlen(src));
	while (*tmpsrc)
	{
		if (length != 1)
		{
			*tmpdst++ = *tmpsrc;
			length--;
		}
		tmpsrc++;
	}
	*tmpdst = '\0';
	return (dsize + (tmpsrc - src));
}
