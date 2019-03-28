/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:55:08 by afrancoi          #+#    #+#             */
/*   Updated: 2019/03/28 18:24:46 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <sys/stat.h>
#include <stdio.h>

int		get_files(char *path)
{
	DIR *dir;
	struct dirent	*file;
	t_file			*start;
	t_file			*elem;

	start = NULL;
	elem = NULL;
	if(!(dir = opendir(path)))
		return (0);
	file = readdir(dir);
	if(!(start = add_node(NULL, file)))
	{
		closedir(dir);
		return (0);
	}
	while((file = readdir(dir)))
	{
		elem = add_node(start, file);
		if(elem->name[0] != '.')
		{
			ft_putstr(elem->name);
			ft_putchar(' ');
		}
	}
	ft_putchar('\n');
	closedir(dir);
	return (1);
}
