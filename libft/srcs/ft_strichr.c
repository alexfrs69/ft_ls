/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:33:10 by afrancoi          #+#    #+#             */
/*   Updated: 2019/04/10 17:18:30 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return index of a char (int c) pointed by str.
*/

int	ft_strichr(char *str, int c)
{
	int i;

	i = 0;
	while (*str++)
	{
		if (*str == c)
			return (i);
		i++;
	}
	return (0);
}
