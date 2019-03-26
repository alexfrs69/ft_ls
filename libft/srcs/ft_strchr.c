/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:46:12 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/11 15:52:53 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char tofind;
	char *str;

	str = (char *)s;
	tofind = (char)c;
	while (*str)
	{
		if (*str == tofind)
			return (str);
		str++;
	}
	if (tofind == '\0')
		return (str);
	return (NULL);
}
