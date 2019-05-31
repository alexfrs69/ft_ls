/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 06:43:47 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/31 11:54:05 by afrancoi         ###   ########.fr       */
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
		if (a->stat.st_mtim.tv_nsec > b->stat.st_mtim.tv_nsec)
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
	if (ft_strcasecmp(a->name, b->name) <= 0)
		return (1);
	else
		return (0);
}
