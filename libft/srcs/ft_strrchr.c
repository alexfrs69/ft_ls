/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:53:22 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/11 15:56:10 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;
	char tofind;
	char *find;

	find = NULL;
	str = (char *)s;
	tofind = (char)c;
	while (*str)
	{
		if (*str == tofind)
			find = str;
		str++;
	}
	if (tofind == '\0')
		return (str);
	return (find);
}
