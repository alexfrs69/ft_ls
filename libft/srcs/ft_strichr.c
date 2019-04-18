/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:33:10 by afrancoi          #+#    #+#             */
/*   Updated: 2019/04/17 22:19:29 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return index of a char (int c) pointed by str.
*/

int		ft_strichr(const char *s, int c)
{
	char	tofind;
	char	*str;
	int		i;

	str = (char *)s;
	tofind = (char)c;
	i = 1;
	if (!tofind)
		return (-1);
	while (*str++)
	{
		if (*str == tofind)
			return (i);
		i++;
	}
	return (-1);
}
