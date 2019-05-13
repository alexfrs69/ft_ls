/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:01:24 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/13 02:39:06 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		fill_node(t_file *elem, t_dirent *file, char *path)
{
	char *tmp;

	if(!file)
		return (0);
	if(!(tmp = join_path(path, file->d_name)))
		return (0);
	ft_strcpy(elem->path, tmp);
	free(tmp);
	lstat(elem->path, &elem->stat);
	elem->file = *file;
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

t_file	*add_node(t_file *start, t_dirent *file, char *path)
{
	t_file	*elem;

	if (!(elem = (t_file*)ft_memalloc(sizeof(t_file))))
		return (NULL);
	fill_node(elem, file, path);
	if (start)
		link_node(start, elem);
	return (elem);
}

t_file *get_start_node(void)
{
	static t_file start;

	return (&start);
}

/* WIP
int		del_node(t_file *elem, t_file *start)
{

}

int		del_list()

t_file	*search_node(t_file *elem, t_file *start)
{

}
*/


