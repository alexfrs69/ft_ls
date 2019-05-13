/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:10:52 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/13 02:49:45 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	display_list(t_file *start)
{
	t_file *elem;

	elem = start;
	while(elem)
	{
		if(elem->file.d_name[0] != '.')
		{
			printf("	%s\n", elem->file.d_name);
		}
		elem = elem->next;
	}
}

void	display_queue(t_queue *queue)
{
	t_queue *elem;

	elem = queue;
	while(elem)
	{
		printf("queue->%s\n", elem->path);
		elem = elem->next;
	}
}
