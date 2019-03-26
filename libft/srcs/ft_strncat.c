/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:29:03 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/10 22:46:22 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ret;
	size_t	len;

	ret = s1;
	len = ft_strlen(s1);
	while (*s2 && n--)
	{
		s1[len++] = *s2++;
	}
	s1[len] = '\0';
	return (ret);
}
