/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:09:01 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/06 20:03:09 by afrancoi         ###   ########.fr       */
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

static t_file	*save_recur_dir(char *path, t_file **new, int opts)
{
	DIR			*dir;
	t_dirent	*dirent;
	t_file		*start;
	char		*tmp;
	t_stat		stat;

	start = NULL;
	if ((dir = opendir(path)))
	{
		while ((dirent = readdir(dir)))
		{
			if (!check(dirent->d_name, opts))
				continue ;
			if (!(tmp = join_path(path, dirent->d_name)))
					continue ;
			lstat(tmp, &stat);
			if (S_ISDIR(stat.st_mode) || S_ISLNK(stat.st_mode))
			{
				*new = init_node(*new, dirent, &stat, path);
				ft_strdel(&tmp);
			}
			start = init_node(start, dirent, &stat, path);
		}
		closedir(dir);
		return (start);
	}
	return (NULL);
}

int				options_recursive(t_file *list, int opts)
{
	t_file		*new;
	t_file		*tmp;
	t_file		*dir;

	dir = NULL;
	new = NULL;
	ft_mergesort(&list, opts);
	tmp = list;
	display_file(list);
	while (list)
	{
		if ((S_ISDIR(list->stat.st_mode)) || (S_ISLNK(list->stat.st_mode)))
		{
			if (!(dir = save_recur_dir(list->path, &new, opts)))
				ft_error(errno, list->path);
		}
		ft_mergesort(&dir, opts);
		display_list(dir, list->path, opts);
		list_del(&dir);
		if (list->next)
			ft_putchar('\n');
		list = list->next;
	}
	list_del(&tmp);
	if (new)
		options_recursive(new, opts);
	return (1);
}
