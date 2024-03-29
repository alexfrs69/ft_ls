/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 06:43:47 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/17 03:41:56 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int		check_time(t_file *a, t_file *b)
{
	return (a->stat.st_mtimespec.tv_sec >= b->stat.st_mtimespec.tv_sec);
}

int		reverse_time(t_file *a, t_file *b)
{
	return (a->stat.st_mtimespec.tv_sec <= b->stat.st_mtimespec.tv_sec);
}

int		check_strcmp(t_file *a, t_file *b)
{
	return (ft_strcmp(a->name, b->name) <= 0);
}

int		reverse_cmp(t_file *a, t_file *b)
{
	return (ft_strcmp(a->name, b->name) >= 0);
}

t_cmp	ft_getcmp(int opts)
{
	if (opts & OPT_T)
	{
		if (opts & OPT_REV)
			return (&reverse_time);
		else
			return (&check_time);
	}
	else if (opts & OPT_REV)
		return (&reverse_cmp);
	else
		return (&check_strcmp);
}
