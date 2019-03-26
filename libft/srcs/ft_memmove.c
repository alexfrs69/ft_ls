/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:25:51 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/10 17:43:51 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmpdst;
	unsigned char *tmpsrc;

	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	if (dst > src)
	{
		while (len--)
			tmpdst[len] = tmpsrc[len];
	}
	else
	{
		while (len--)
			*tmpdst++ = *tmpsrc++;
	}
	return (dst);
}
