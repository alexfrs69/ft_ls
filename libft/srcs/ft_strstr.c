/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:35:12 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/11 19:47:47 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	nsize;
	char	*ret;

	ret = (char*)haystack;
	nsize = ft_strlen(needle);
	if (!nsize)
		return (ret);
	while (*ret)
	{
		if (!ft_memcmp(ret, needle, nsize))
			return (ret);
		ret++;
	}
	return (NULL);
}
