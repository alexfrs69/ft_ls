/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:35:09 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/15 21:35:13 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprime(int nb)
{
	int i;

	if (nb < 2)
		return (0);
	else if (nb <= 3)
		return (1);
	else if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	else
	{
		i = 5;
		while (i <= nb / 2)
		{
			if (nb % i == 0)
				return (0);
			else
			{
				i += 2;
			}
		}
		return (1);
	}
}
