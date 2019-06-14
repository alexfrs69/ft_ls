/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:01:24 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/14 01:39:14 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	stat_wrapper(t_file *elem, t_stat *stat, char *path)
{
	if (!elem)
		return ;
	if (!stat)
		lstat(path, &elem->stat);
	else
		ft_memcpy(&elem->stat, stat, sizeof(t_stat));
}

int		fill_node(t_file *elem, t_dirent *dirent, t_stat *stat, char *path)
{
	if (dirent)
		ft_strcpy(elem->name, dirent->d_name);
	else
		ft_strcpy(elem->name, path);
	ft_strcpy(elem->path, path);
	stat_wrapper(elem, stat, path);
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

t_file	*add_node(t_file *start, t_dirent *dirent, t_stat *stat, char *path)
{
	t_file	*elem;

	if (!(elem = (t_file*)ft_memalloc(sizeof(t_file))))
		return (NULL);
	elem->next = NULL;
	fill_node(elem, dirent, stat, path);
	if (start)
		link_node(start, elem);
	return (elem);
}

void	list_del(t_file **start)
{
	t_file *tmp;
	t_file *tmp2;

	if (!*start)
		return ;
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
