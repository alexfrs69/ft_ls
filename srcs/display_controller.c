/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:10:52 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/16 02:19:38 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	display_list(t_file *start, char *path)
{
	t_file *elem;

	if(!start)
		return ;
	ft_putendl(path);
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
