/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:49:53 by afrancoi          #+#    #+#             */
/*   Updated: 2019/10/30 18:53:36 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <errno.h>

static char	*check(char *name, char *path, int listopt)
{
	char *ret;

	ret = NULL;
	if (!(listopt & OPT_A))
		if (name[0] == '.')
			return (NULL);
	if (!(ret = ft_pathjoin(path, name)))
		return (NULL);
	return (ret);
}

int			save_dir(char *path, int listopt)
{
	DIR				*dir;
	t_dirent		*dirent;
	t_file			*start;
	char			*tmp;

	start = NULL;
	if (!(dir = opendir(path)))
	{
		ft_error(errno, path);
		return (0);
	}
	while ((dirent = readdir(dir)))
	{
		if (!(tmp = check(dirent->d_name, path, listopt)))
			continue ;
		start = init_node(start, dirent, NULL, tmp);
		ft_strdel(&tmp);
	}
	closedir(dir);
	ft_mergesort(&start, listopt);
	display_list(start, path, listopt);
	list_del(&start);
	return (1);
}

void		save_list_dir(t_file *list, int listopts)
{
	t_file *cur;

	cur = list;
	while (cur)
	{
		if ((S_ISDIR(cur->stat.st_mode))
			|| (S_ISLNK(cur->stat.st_mode) && !(listopts & OPT_L)))
			save_dir(cur->path, listopts);
		if ((cur = cur->next))
			if (S_ISDIR(cur->stat.st_mode))
				ft_putchar('\n');
	}
	list_del(&list);
}

void		route_to(t_file *list, int listopts)
{
	ft_mergesort(&list, listopts);
	display_file(list, listopts);
	if ((listopts & OPT_R))
		options_recursive(list, listopts);
	else
		save_list_dir(list, listopts);
}
