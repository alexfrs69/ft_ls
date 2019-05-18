/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:09:01 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/18 02:29:39 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char			*join_path(char *path, char *name)
{
	char *ret;
	char *tmp;

	if(*path == '/' && ft_strlen(path) == 1)
		return (ft_strjoin(path, name));
	tmp = ft_strjoin(path, "/");
	ret = ft_strjoin(tmp, name);
	free(tmp);
	return (ret);
}

static int	save_dir(char *path, t_queue **newqueue, t_file **start)
{
	DIR			*dir;
	t_dirent	*dirent;

	if ((dir = opendir(path)))
	{
		while ((dirent = readdir(dir)))
		{
			if (ft_strequ(dirent->d_name, ".")
				|| ft_strequ(dirent->d_name, ".."))
				continue ;
			if (!*start)
				if (!(*start = add_node(NULL, dirent, path)))
					return (-1);
			if (dirent->d_type & DT_DIR)
			{
				if (!*newqueue)
					*newqueue = queue_add(NULL,
						join_path(path, dirent->d_name));
				else
					queue_add(*newqueue,
						join_path(path, dirent->d_name));
			}
			add_node(*start, dirent, path);
		}
		closedir(dir);
		return (1);
	}
	return (0);
}

static int		recur_queue_file(t_queue *queue)
{
	t_queue		*newqueue;
	t_file		*start;

	newqueue = NULL;
	start = NULL;
	while (queue)
	{
		if(!save_dir(queue->path, &newqueue, &start))
		{
			if (start)
				add_node(start, NULL, queue->path);
			else
				start = add_node(NULL, NULL, queue->path);
		}
		display_list(start, queue->path);
		list_del(&start);
		queue = queue->next;
	}
	queue_del(queue);
	if (newqueue)
		recur_queue_file(newqueue);
	return (1);
}

void			options_recursive(t_queue *queue, int listoptions)
{
	listoptions = 0;
	recur_queue_file(queue);
}
