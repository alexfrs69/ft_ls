/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:10:52 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/19 07:12:38 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	display_list(t_file *start, char *path)
{
	t_file *elem;

	if (!start)
		return ;
	elem = start;
	if (ft_strlen(elem->dirent.d_name))
		ft_putendl(path);
	while (elem)
	{
		if (ft_strlen(elem->dirent.d_name))
		{
			printf("	%s\n", elem->dirent.d_name);
		}
		else
			printf("%s \n", elem->path);
		elem = elem->next;
	}
}

void	display_queue(t_queue *queue)
{
	t_queue *elem;

	elem = queue;
	while (elem)
	{
		printf("queue->%s\n", elem->path);
		elem = elem->next;
	}
}
