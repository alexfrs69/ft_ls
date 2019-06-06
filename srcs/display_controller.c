/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:10:52 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/06 22:43:48 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	display_list(t_file *start, char *path, int opts)
{
	t_file *elem;

	if (!start)
		return ;
	elem = start;
	if (opts & OPT_L)
		return (display_opt_l(start, path, opts));
	if ((opts & OPTS || opts & OPT_R) && start->infodir)
		printf("%s:\n", path);
	while (elem)
	{
		printf("%s\n", elem->name);
		elem = elem->next;
	}
}

void	display_file(t_file *list)
{
	t_file *elem;

	if(!list)
		return ;
	elem = list;
	while (elem)
	{
		if (!(S_ISDIR(elem->stat.st_mode)))
		{
			printf("%s\n", elem->name);
			if (elem->next)
				ft_putchar('\n');
		}
		elem = elem->next;
	}
}
