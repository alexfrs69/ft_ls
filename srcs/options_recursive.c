/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:09:01 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/25 09:05:58 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <errno.h>

char			*join_path(char *path, char *name)
{
	char *ret;
	char *tmp;

	if (*path == '/' && ft_strlen(path) == 1)
		return (ft_strjoin(path, name));
	tmp = ft_strjoin(path, "/");
	ret = ft_strjoin(tmp, name);
	free(tmp);
	return (ret);
}

static int		check(char *name, int opts)
{
	if (ft_strequ(name, ".")
		|| ft_strequ(name, ".."))
		return (0);
	if (!(opts & OPT_A))
		if (name[0] == '.')
			return (0);
	return (1);
}

static t_file	*save_dir(char *path, t_queue **newqueue, int opts)
{
	DIR			*dir;
	t_dirent	*dirent;
	t_file		*start;
	char		*tmp;

	start = NULL;
	if ((dir = opendir(path)))
	{
		while ((dirent = readdir(dir)))
		{
			if (!check(dirent->d_name, opts))
				continue ;
			if (dirent->d_type & DT_DIR)
			{
				if (!(tmp = join_path(path, dirent->d_name)))
					continue ;
				*newqueue = init_queue(*newqueue, tmp);
				ft_strdel(&tmp);
			}
			start = init_node(start, dirent, path);
		}
		closedir(dir);
		return (start);
	}
	return (NULL);
}

int				options_recursive(t_queue *queue, int opts)
{
	t_queue		*newqueue;
	t_file		*start;
	t_queue		*tmp;
	t_stat		stat;

	tmp = queue;
	ft_mergesort_tqueue(&queue);
	newqueue = NULL;
	start = NULL;
	while (queue)
	{
		lstat(queue->path, &stat);
		if ((S_ISDIR(stat.st_mode)) || (S_ISLNK(stat.st_mode)))
		{
			if (!(start = save_dir(queue->path, &newqueue, opts)))
				ft_error(errno, queue->path);
		}
		else
			start = init_node(start, NULL, queue->path);
		ft_mergesort_tfile(&start);
		display_list(start, queue->path);
		list_del(&start);
		queue = queue->next;
	}
	queue_del(&tmp);
	if (newqueue)
		options_recursive(newqueue, opts);
	return (1);
}
