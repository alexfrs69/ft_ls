/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:43:36 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/06 23:29:31 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>

static void	perm(t_file *elem)
{
	ft_putchar((S_ISDIR(elem->stat.st_mode)) ? 'd' : '-');
	ft_putchar((elem->stat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((elem->stat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((elem->stat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((elem->stat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((elem->stat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((elem->stat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((elem->stat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((elem->stat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((elem->stat.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putchar(' ');
}

static void	userngroup(t_file *elem)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(elem->stat.st_uid);
	ft_putstr(pwd->pw_name);
	ft_putchar(' ');
	grp = getgrgid(elem->stat.st_gid);
	ft_putstr(grp->gr_name);
	ft_putchar(' ');
}

void		display_opt_l(t_file *list, char *path, int opts)
{
	t_file *cur;

	cur = list;
	if ((opts & OPTS || opts & OPT_R) && list->infodir)
		printf("%s:\n", path);
	while (cur)
	{
		perm(cur);
		userngroup(cur);
		ft_putchar('\n');
		cur = cur->next;
	}
}
