/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:49:53 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/25 09:23:09 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <errno.h>

int		save_file(char *path, int listopt)
{
	DIR				*dir;
	t_dirent		*dirent;
	t_file			*start;

	start = NULL;
	if (!(dir = opendir(path)))
	{
		ft_error(errno, path);
		return (0);
	}
	while ((dirent = readdir(dir)))
	{
		if (!(listopt & OPT_A))
			if (dirent->d_name[0] == '.')
				continue ;
		start = init_node(start, dirent, path);
	}
	closedir(dir);
	ft_mergesort_tfile(&start);
	display_list(start, path);
	list_del(&start);
	return (1);
}

void	queue_file(t_queue *queue, int listopt)
{
	t_queue			*tmp;

	tmp = queue;
	ft_mergesort_tqueue(&tmp);
	while (tmp)
	{
		save_file(tmp->path, listopt);
		tmp = tmp->next;
	}
	queue_del(&queue);
}
