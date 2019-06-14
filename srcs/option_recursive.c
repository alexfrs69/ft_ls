/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_recursive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:09:01 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/14 05:37:48 by afrancoi         ###   ########.fr       */
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

static char		*check(char *name, char *path, int opts)
{
	char *ret;

	ret = NULL;
	if (ft_strequ(name, ".")
		|| ft_strequ(name, ".."))
		return (0);
	if (!(opts & OPT_A))
		if (name[0] == '.')
			return (0);
	if (!(ret = join_path(path, name)))
		return (0);
	return (ret);
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
			if (!(tmp = check(dirent->d_name, path, opts)))
				continue ;
			lstat(tmp, &stat);
			if (S_ISDIR(stat.st_mode)
				|| (S_ISLNK(stat.st_mode) && is_link_dir(tmp)))
				*new = init_node(*new, dirent, &stat, tmp);
			ft_strdel(&tmp);
			start = init_node(start, dirent, &stat, path);
		}
		closedir(dir);
		return (start);
	}
	return (NULL);
}

static	t_file	*recur_wrapper(t_file *elem, t_file **new, int opts)
{
	t_file *dir;

	dir = NULL;
	if ((S_ISDIR(elem->stat.st_mode)) || S_ISLNK(elem->stat.st_mode))
	{
		if (S_ISLNK(elem->stat.st_mode) && (opts & OPT_L))
		{
			display_l_wrapper(elem);
			return (NULL);
		}
		else
		{
			if (!(dir = save_recur_dir(elem->path, new, opts)))
			{
				ft_error(errno, elem->path);
				return (NULL);
			}
		}
	}
	return (dir);
}

int				options_recursive(t_file *list, int opts)
{
	t_file		*new;
	t_file		*tmp;
	t_file		*dir;

	dir = NULL;
	ft_mergesort(&list, opts);
	tmp = list;
	while (list)
	{
		new = NULL;
		dir = recur_wrapper(list, &new, opts);
		ft_mergesort(&dir, opts);
		display_list(dir, list->path, opts);
		list_del(&dir);
		if ((list = list->next))
			if (!S_ISREG(list->stat.st_mode))
				ft_putchar('\n');
		new ? options_recursive(new, opts) : 0;
	}
	if (tmp)
		list_del(&tmp);
	return (1);
}
