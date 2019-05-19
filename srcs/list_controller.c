/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:01:24 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/19 06:55:28 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		fill_node(t_file *elem, t_dirent *dirent, char *path)
{
	char *tmp;

	if (dirent)
	{
		if (!(tmp = join_path(path, dirent->d_name)))
			return (0);
		elem->dirent = *dirent;
	}
	else
		tmp = path;
	ft_strcpy(elem->path, tmp);
	free(tmp);
	lstat(elem->path, &elem->stat);
	return (1);
}

void	link_node(t_file *start, t_file *elem)
{
	t_file *tmp;

	if (!start || !elem)
		return ;
	tmp = start;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
}

t_file	*add_node(t_file *start, t_dirent *dirent, char *path)
{
	t_file	*elem;

	if (!(elem = (t_file*)ft_memalloc(sizeof(t_file))))
		return (NULL);
	fill_node(elem, dirent, path);
	if (start)
		link_node(start, elem);
	return (elem);
}

void	list_del(t_file **start)
{
	t_file *tmp;
	t_file *tmp2;

	tmp = *start;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		if (tmp2)
			free(tmp2);
	}
	*start = NULL;
}

