/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:34:05 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/15 21:34:13 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	return (nb * ft_factorial(nb - 1));
}