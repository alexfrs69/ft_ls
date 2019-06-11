/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:49:53 by afrancoi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/06/11 03:17:02 by afrancoi         ###   ########.fr       */
=======
/*   Updated: 2019/06/07 16:35:16 by afrancoi         ###   ########.fr       */
>>>>>>> 96716d9dcb93cec518a2eb5f38a5371001d88cf9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <errno.h>

int		save_dir(char *path, int listopt)
{
	DIR				*dir;
	t_dirent		*dirent;
	t_file			*start;

	start = NULL;
	if (!(dir = opendir(path)))
	{
		ft_error(errno, path);
		return (0);
	}
	while ((dirent = readdir(dir)))
	{
		if (!(listopt & OPT_A))
			if (dirent->d_name[0] == '.')
				continue ;
		start = init_node(start, dirent, NULL, path);
	}
	closedir(dir);
	ft_mergesort(&start, listopt);
	display_list(start, path, listopt);
	list_del(&start);
	return (1);
}

void	save_list_dir(t_file *list, int listopts)
{
	t_file *cur;

	cur = list;
	ft_mergesort(&cur, listopts);
	display_file(cur, listopts);
	while (cur)
	{
		if ((S_ISDIR(cur->stat.st_mode)))
			save_dir(cur->path, listopts);
<<<<<<< HEAD
		if (cur->next)
=======
		if(cur->next)
>>>>>>> 96716d9dcb93cec518a2eb5f38a5371001d88cf9
			ft_putchar('\n');
		cur = cur->next;
	}
	list_del(&list);
}
