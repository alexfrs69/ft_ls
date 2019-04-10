/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:39:26 by afrancoi          #+#    #+#             */
/*   Updated: 2019/04/10 16:45:14 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return result of base power of exponent.
*/

double	ft_pow(double base, double exponent)
{
	double i;
	double number;

	i = -1;
	number = 1;
	while (++i < exponent)
		number *= base;
	return (number);
}
