/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:24:36 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/10 22:46:12 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len;
	char	*ret;

	ret = s1;
	len = ft_strlen(s1);
	while (*s2)
	{
		s1[len++] = *s2++;
	}
	s1[len] = '\0';
	return (ret);
}
