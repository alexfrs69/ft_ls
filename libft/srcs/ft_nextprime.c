/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:36:14 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/15 21:36:51 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nextprime(int nb)
{
	if (nb < 2)
		return (2);
	if (ft_isprime(nb))
		return (nb);
	else
		return (ft_nextprime(nb + 1));
}
