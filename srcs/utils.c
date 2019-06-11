/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 01:22:05 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/11 02:54:00 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*init_node(t_file *start, t_dirent *dirent, t_stat *stat, char *path)
{
	if (start)
		add_node(start, dirent, stat, path);
	else
		start = add_node(NULL, dirent, stat, path);
	return (start);
}

int	get_total_size(t_file *list)
{
	int total;

	total = 0;
	while(list)
	{
		total += (int)list->stat.st_blocks;
		list = list->next;
	}
	return (total);
}

