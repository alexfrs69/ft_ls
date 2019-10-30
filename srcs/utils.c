/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 01:22:05 by afrancoi          #+#    #+#             */
/*   Updated: 2019/10/30 19:57:44 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <unistd.h>

t_file	*init_node(t_file *start, t_dirent *dirent, t_stat *stat, char *path)
{
	if (start)
		add_node(start, dirent, stat, path);
	else
		start = add_node(NULL, dirent, stat, path);
	return (start);
}

int		get_total_size(t_file *list)
{
	int total;

	total = 0;
	while (list)
	{
		total += (int)list->stat.st_blocks;
		list = list->next;
	}
	return (total);
}

int		is_link_dir(char *path)
{
	char	buf[PATH_MAX + 1];
	t_stat	stat;
	int		n;

	if ((n = readlink(path, buf, PATH_MAX)) != -1)
	{
		buf[n] = '\0';
		lstat(buf, &stat);
		if (S_ISDIR(stat.st_mode))
			return (1);
		else
			return (0);
	}
	return (0);
}

char	*ft_check_paths(t_file *elem, int opts, int *malloced)
{
	char *fullpath;

	if ((opts & OPT_R) && ft_strequ(elem->name, elem->path))
		fullpath = elem->path;
	else if (opts & OPT_R)
	{
		fullpath = ft_pathjoin(elem->path, elem->name);
		*malloced = 1;
	}
	else
		fullpath = elem->path;
	return (fullpath);
}
