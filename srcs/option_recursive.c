/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_recursive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:09:01 by afrancoi          #+#    #+#             */
/*   Updated: 2019/07/23 23:46:51 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <errno.h>

static int		ft_opts_a(char *name)
{
	if (ft_strequ(name, "."))
		return (0);
	if (ft_strequ(name, ".."))
		return (0);
	return (1);
}

static char		*check(char *name, char *path, int opts)
{
	char *ret;

	ret = NULL;
	if (!(opts & OPT_A))
		if (name[0] == '.')
			return (0);
	if (!(ret = ft_pathjoin(path, name)))
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
			if ((S_ISDIR(stat.st_mode)
				|| (S_ISLNK(stat.st_mode))) && is_link_dir(tmp)
				&& ft_opts_a(dirent->d_name))
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

	*new = NULL;
	dir = NULL;
	if ((S_ISDIR(elem->stat.st_mode))
		|| (S_ISLNK(elem->stat.st_mode) && !(opts & OPT_L)))
	{
		if (!(dir = save_recur_dir(elem->path, new, opts)))
		{
			ft_error(errno, elem->path);
			return (NULL);
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
		if ((dir = recur_wrapper(list, &new, opts)))
		{
			ft_mergesort(&dir, opts);
			display_list(dir, list->path, opts);
			list_del(&dir);
		}
		if (new)
		{
			ft_putchar('\n');
			options_recursive(new, opts);
		}
		if ((list = list->next))
			S_ISDIR(list->stat.st_mode) ? ft_putchar('\n') : 0;
	}
	tmp ? list_del(&tmp) : 0;
	return (1);
}
