/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:13:59 by afrancoi          #+#    #+#             */
/*   Updated: 2019/04/24 04:32:46 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	queue_link(t_queue *start, t_queue *new)
{
	t_queue *tmp;

	tmp = start;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_queue	*queue_add(t_queue *start, char *path)
{
	t_queue *elem;

	if (ft_strlen(path) >= PATH_MAX)
		return (NULL);
	if (!(elem = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	queue_fill(elem, path);
	if (start)
		queue_link(start, elem);
	return (elem);
}

void	queue_fill(t_queue *elem, char *path)
{
	ft_strcpy(elem->path, path);
}

/*int		queue_del(t_queue *start, t_queue *elem)
{

}*/

t_queue *get_queue_node(void)
{
	static t_queue queue;

	return (&queue);
}
