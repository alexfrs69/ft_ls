/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:49:53 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/08 01:09:30 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int save_file(char *path, t_file *start)
{
	DIR				*dir;
	t_dirent		*file;
	printf("before open dir %s\n", path);
	if(!(dir = opendir(path)))
		return (0);
	printf("DEBUG ** opened %s\n", path);
	if(ft_strlen(start->file.d_name) == 0)
		fill_node(start, readdir(dir), path);
	while((file = readdir(dir)))
		add_node(start, file, path);
	closedir(dir);
	return (1);
}

void	queue_file(t_queue *queue, int listopt)
{
	t_queue			*tmp;
	t_file			*start;

	listopt = 0;
	start = get_start_node();
	tmp = queue;
	while (tmp)
	{
		save_file(tmp->path, start);
		tmp = tmp->next;
	}
	display_list(start);
}
