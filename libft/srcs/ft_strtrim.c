/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:13:03 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/14 02:51:24 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	int				end;
	size_t			len;
	char			*ret;

	if (!s)
		return (NULL);
	while (ft_isspace(*s) && *s)
		s++;
	end = ft_strlen(s) - 1;
	while (ft_isspace(s[end]))
		end--;
	if (end <= 0)
		len = 0;
	else
		len = end + 1;
	ret = (char*)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
		ret[i++] = *s++;
	ret[i] = '\0';
	return (ret);
}
