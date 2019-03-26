/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:17:24 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/12 16:04:53 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*tofind;
	size_t	size;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack && len--)
	{
		if (*haystack == *needle)
		{
			size = len;
			str = (char*)haystack + 1;
			tofind = (char*)needle + 1;
			while (size-- && *str == *tofind && *str && *tofind)
			{
				str++;
				tofind++;
			}
			if (!*tofind)
				return ((char*)haystack);
		}
		haystack++;
	}
	return (NULL);
}
