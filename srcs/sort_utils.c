/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 06:43:47 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/06 20:12:38 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int		check_time(t_file *a, t_file *b)
{
	long int	asec;
	long int	bsec;
	int			ret;

	asec = a->stat.st_mtim.tv_sec;
	bsec = b->stat.st_mtim.tv_sec;
	if (asec > bsec)
		ret = 1;
	else if (asec == bsec)
	{
		if (a->stat.st_mtim.tv_nsec >= b->stat.st_mtim.tv_nsec)
			ret = 1;
		else
			ret = 0;
	}
	else
		ret = 0;
	return(ret);
}

int		check_strcmp(t_file *a, t_file *b)
{
	return (ft_strcasecmp(a->name, b->name) <= 0);
}

int		reverse_cmp(t_file *a, t_file *b)
{
	return (ft_strcasecmp(a->name, b->name) >= 0);
}

t_cmp ft_getcmp(int opts)
{
	if (opts & OPT_T)
		return (&check_time);
	else if (opts & OPT_REV)
		return (&reverse_cmp);
	else
		return (&check_strcmp);
}
