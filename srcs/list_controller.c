/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:01:24 by afrancoi          #+#    #+#             */
/*   Updated: 2019/04/24 03:43:06 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		fill_node(t_file *elem, t_dirent *file)
{
	stat(file->d_name, &elem->stat);
	elem->file = *file;
	return (1);
}

void	link_node(t_file *start, t_file *elem)
{
	t_file *tmp;

	tmp = start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
}

t_file	*add_node(t_file *start, t_dirent *file)
{
	t_file	*elem;

	if (!(elem = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	fill_node(elem, file);
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


