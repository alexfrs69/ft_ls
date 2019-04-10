/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:49:53 by afrancoi          #+#    #+#             */
/*   Updated: 2019/04/02 12:17:19 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int save_file(char *path)
{
	DIR				*dir;
	t_dirent		*file;
	t_file			*start;
	t_file			*elem;

	start = get_start_node();
	elem = NULL;
	if(!(dir = opendir(path)))
		return (0);
	if(ft_strlen(start->file.d_name) == 0)
		fill_node(start, readdir(dir));
	while((file = readdir(dir)))
			elem = add_node(start, file);
	closedir(dir);
	return (1);
}
/* TODO
int save_recusive_file(char *path)
{
	DIR				*dir;
	t_dirent		*file;
	t_file			*start;
	t_file			*elem;

	start = get_start_node();
	elem = NULL;
	if(!(dir = opendir(path)))
		return (0);
	if(ft_strlen(start->file.d_name) == 0)
		fill_node(start, readdir(dir));
	while((file = readdir(dir)))
			elem = add_node(start, file);
	closedir(dir);
	return (1);
}
*/
