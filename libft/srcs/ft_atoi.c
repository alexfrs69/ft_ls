/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:29:13 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/14 22:00:04 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int ret;
	int min;

	ret = 0;
	min = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			min = 1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	if (min)
		return (-ret);
	else
		return (ret);
}
