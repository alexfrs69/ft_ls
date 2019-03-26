/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 07:45:37 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/02 13:31:39 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_sqrt(int nb, int count)
{
	double	x;
	int		rnds;

	if (!count || count < 0)
		count = 5;
	rnds = -1;
	x = nb / 2;
	while (++rnds < count)
		x = (x + nb / x) * 0.5;
	return (x);
}
