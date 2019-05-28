/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 01:22:05 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/25 01:28:55 by afrancoi         ###   ########.fr       */
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

t_queue	*init_queue(t_queue *start, char *path)
{
	if (start)
		queue_add(start, path);
	else
		start = queue_add(NULL, path);
	return (start);
}
