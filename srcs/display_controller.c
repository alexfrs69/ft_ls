/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:10:52 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/11 03:06:34 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void		display_opt_l(t_file *list, char *path, int opts)
{
	t_file	*cur;

	cur = list;
	if (((opts & OPTS) || (opts & OPT_R)) && path)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
	if (path)
	{
		ft_putstr("total ");
		ft_putnbr(get_total_size(list));
		ft_putchar('\n');
	}
	while (cur)
	{
		display_l_wrapper(cur);
		cur = cur->next;
	}
}

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

void	display_file(t_file *list, int opts)
{
	t_file *elem;

	if(!list)
		return ;
	if (opts & OPT_L)
		return (display_opt_l(list, NULL, opts));
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
