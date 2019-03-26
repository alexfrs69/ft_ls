/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 00:38:03 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/14 01:55:29 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_countchar(int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

static int	ft_isneg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		size;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = ft_isneg(n);
	neg ? n = -n : 0;
	size = ft_countchar(n);
	size += neg;
	if (!(ret = ft_strnew(size)))
		return (NULL);
	while (size--)
	{
		ret[size] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		ret[0] = '-';
	return (ret);
}
