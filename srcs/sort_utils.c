/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 06:43:47 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/30 12:48:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <time.h>

int		check_time(t_file *a, t_file *b)
{
	if (a->stat.st_mtime >= b->stat.st_mtime)
		return (1);
	else
		return (0);
}

int		check_strcmp(t_file *a, t_file *b)
{
	if (ft_strcasecmp(a->name, b->name) <= 0)
		return (1);
	else
		return (0);
}
