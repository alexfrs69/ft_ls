/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:10:52 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/17 03:38:13 by afrancoi         ###   ########.fr       */
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
	if (!list)
		return ;
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

void		display_list(t_file *start, char *path, int opts)
{
	t_file *elem;

	elem = start;
	if (opts & OPT_L)
		return (display_opt_l(start, path, opts));
	if (((opts & OPTS) || (opts & OPT_R)) && path)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
	if (!start)
		return ;
	while (elem)
	{
		ft_putendl(elem->name);
		elem = elem->next;
	}
}

void		display_file(t_file *list, int opts)
{
	t_file	*elem;
	int		nw;

	nw = 0;
	if (!list)
		return ;
	elem = list;
	while (elem)
	{
		if (!S_ISDIR(elem->stat.st_mode))
		{
			if (opts & OPT_L)
				display_l_wrapper(elem);
			else if (!S_ISLNK(elem->stat.st_mode))
				ft_putendl(elem->name);
		}
		else if (!nw)
			nw = 1;
		elem = elem->next;
	}
	if (nw && !(opts & OPT_L))
		ft_putchar('\n');
}
