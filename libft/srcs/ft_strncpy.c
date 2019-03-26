/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:05:45 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/10 16:39:09 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *tmpdst;

	tmpdst = dst;
	while (*src)
	{
		if (!len--)
			return (tmpdst);
		*dst++ = *src++;
	}
	while (len--)
		*dst++ = '\0';
	return (tmpdst);
}
