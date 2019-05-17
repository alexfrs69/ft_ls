/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:49:53 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/17 03:20:43 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int save_file(char *path)
{
	DIR				*dir;
	t_dirent		*file;
	t_file			*start;

	if (!(dir = opendir(path)))
		return (0);
	start = add_node(NULL, readdir(dir), path);
	while ((file = readdir(dir)))
		add_node(start, file, path);
	closedir(dir);
	display_list(start, path);
	list_del(&start);
	return (1);
}

void	queue_file(t_queue *queue, int listopt)
{
	t_queue			*tmp;
	t_file			*start;

	listopt = 0;
	tmp = queue;
	start = NULL;
	while (tmp)
	{
		save_file(tmp->path);
		tmp = tmp->next;
	}
}
