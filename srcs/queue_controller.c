/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:13:59 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/24 00:17:05 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	queue_link(t_queue *start, t_queue *new)
{
	t_queue *tmp;

	if (!start || !new)
		return ;
	tmp = start;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_queue	*queue_add(t_queue *start, char *path)
{
	t_queue *elem;

	if (ft_strlen(path) >= PATH_MAX)
		return (NULL);
	if (!(elem = (t_queue*)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	elem->next = NULL;
	queue_fill(elem, path);
	if (start)
		queue_link(start, elem);
	return (elem);
}

void	queue_fill(t_queue *elem, char *path)
{
	ft_strcpy(elem->path, path);
}

void	queue_del_elem(t_queue *start, t_queue *elem)
{
	t_queue *tmp;

	tmp = start;
	while (tmp->next != elem && tmp)
		tmp = tmp->next;
	if (tmp)
	{
		if (tmp->next->next)
			tmp->next = tmp->next->next;
		else
			tmp->next = NULL;
		free(tmp->next);
	}
}

void	queue_del(t_queue **start)
{
	t_queue *tmp;
	t_queue *tmp2;

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
