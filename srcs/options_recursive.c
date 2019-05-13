/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:09:01 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/13 04:33:13 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char	*join_path(char *path, char *name)
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

static int	recur_queue_file(t_queue *queue, t_file *start)
{
	DIR			*dir;
	t_dirent	*file;
	t_queue		*newqueue;

	newqueue = NULL;
	while (queue)
	{
		if (!(dir = opendir(queue->path)))
		{
			queue = queue->next;
			continue ;
		}
		if (ft_strlen(start->file.d_name) == 0)
			fill_node(start, readdir(dir), queue->path);
		printf("%s :\n", queue->path);
		while ((file = readdir(dir)))
		{
			if(file->d_name[0] == '.')
				continue ;
			if(file->d_type & DT_DIR)
			{
				if (!newqueue)
					newqueue = queue_add(NULL, join_path(queue->path, file->d_name));
				else
					queue_add(newqueue, join_path(queue->path, file->d_name));
			}
			add_node(start, file, queue->path);
		}
		closedir(dir);
		display_list(start);
		queue = queue->next;
	}
	queue_del(queue);
	if (newqueue)
		recur_queue_file(newqueue, start);
	return (1);
}

void		options_recursive(t_queue *queue, int listoptions)
{
	t_file *start;

	listoptions = 0;
	start = get_start_node();
	recur_queue_file(queue, start);
}
