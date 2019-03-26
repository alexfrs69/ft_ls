/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:33:18 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/09 19:15:34 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *tmpdst;
	unsigned char *tmpsrc;

	tmpdst = (unsigned char*)dst;
	tmpsrc = (unsigned char *)src;
	while (n--)
	{
		*tmpdst++ = *tmpsrc++;
		if (*(tmpsrc - 1) == (unsigned char)c)
			return (tmpdst);
	}
	return (NULL);
}
