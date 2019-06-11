/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:10:52 by afrancoi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/06/11 03:29:32 by afrancoi         ###   ########.fr       */
=======
/*   Updated: 2019/06/07 16:34:16 by afrancoi         ###   ########.fr       */
>>>>>>> 96716d9dcb93cec518a2eb5f38a5371001d88cf9
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

void	display_list(t_file *start, char *path, int opts)
{
	t_file *elem;

	elem = start;
	if (opts & OPT_L)
		return (display_opt_l(start, path, opts));
	if ((opts & OPTS) || (opts & OPT_R))
		printf("%s:\n", path);
	if (!start)
		return ;
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
		if (S_ISREG(elem->stat.st_mode))
		{
			printf("%s\n", elem->name);
			if (elem->next)
				ft_putchar('\n');
		}
		elem = elem->next;
	}
}
