/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:10:52 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/25 09:13:02 by afrancoi         ###   ########.fr       */
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
	if (elem->infodir && !ft_strequ(path, "."))
		printf("%s:\n", path);
	while (elem)
	{
		if (ft_strequ(path, "."))
		{
			if(elem->next)
				printf("%10s", elem->name);
			else
				printf("%10s\n", elem->name);
		}
		else
			printf("	%s\n", elem->name);
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
