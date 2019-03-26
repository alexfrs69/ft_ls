/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:08:35 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/14 02:51:12 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	size1;
	size_t	size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ret = (char*)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, size1);
	ft_memcpy(ret + size1, s2, size2);
	ret[size1 + size2] = '\0';
	return (ret);
}
