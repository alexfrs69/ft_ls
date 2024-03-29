/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:43:36 by afrancoi          #+#    #+#             */
/*   Updated: 2019/10/30 19:53:25 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/xattr.h>

static void		ft_time(t_file *cur)
{
	char	*str;
	time_t	sixmonth;
	time_t	now;
	time_t	mtime;

	ft_putchar(' ');
	mtime = cur->stat.st_mtime;
	sixmonth = 15552000;
	str = ctime(&cur->stat.st_mtime);
	now = time(NULL);
	if ((now < mtime) || ((now - mtime) > sixmonth))
	{
		str[11] = '\0';
		str[24] = '\0';
		ft_putstr(str + 4);
		ft_putstr(str + 20);
	}
	else
	{
		str[16] = '\0';
		ft_putstr(str + 4);
	}
	ft_putchar(' ');
}

static void		ft_userngroup(t_file *elem)
{
	struct passwd	*pwd;
	struct group	*grp;

	if (!(pwd = getpwuid(elem->stat.st_uid)))
		ft_putnbr(elem->stat.st_uid);
	else
		ft_putstr(pwd->pw_name);
	ft_putchar(' ');
	if (!(grp = getgrgid(elem->stat.st_gid)))
		ft_putnbr(elem->stat.st_gid);
	else
		ft_putstr(grp->gr_name);
	ft_putchar(' ');
	if ((S_ISCHR(elem->stat.st_mode)) || (S_ISBLK(elem->stat.st_mode)))
	{
		ft_putnbr(major(elem->stat.st_rdev));
		ft_putstr(", ");
		ft_putnbr(minor(elem->stat.st_rdev));
	}
	else
		ft_putnbr(elem->stat.st_size);
	ft_time(elem);
}

static void		ft_perm(t_file *elem)
{
	ft_putchar((elem->stat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((elem->stat.st_mode & S_IWUSR) ? 'w' : '-');
	if (elem->stat.st_mode & S_ISUID)
		ft_putchar((elem->stat.st_mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((elem->stat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((elem->stat.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((elem->stat.st_mode & S_IWGRP) ? 'w' : '-');
	if (elem->stat.st_mode & S_ISGID)
		ft_putchar((elem->stat.st_mode & S_IXGRP) ? 's' : 'S');
	else
		ft_putchar((elem->stat.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((elem->stat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((elem->stat.st_mode & S_IWOTH) ? 'w' : '-');
	if (elem->stat.st_mode & S_ISVTX)
		ft_putchar((elem->stat.st_mode & S_IXOTH) ? 't' : 'T');
	else
		ft_putchar((elem->stat.st_mode & S_IXOTH) ? 'x' : '-');
	if (listxattr(elem->path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	ft_putchar(' ');
	ft_putnbr(elem->stat.st_nlink);
	ft_putchar(' ');
	ft_userngroup(elem);
}

static void		ft_typenperm(t_file *elem)
{
	mode_t type;

	type = elem->stat.st_mode;
	if (S_ISDIR(type))
		ft_putchar('d');
	else if (S_ISREG(type))
		ft_putchar('-');
	else if (S_ISBLK(type))
		ft_putchar('b');
	else if (S_ISCHR(type))
		ft_putchar('c');
	else if (S_ISLNK(type))
		ft_putchar('l');
	else if (S_ISSOCK(type))
		ft_putchar('s');
	else if (S_ISFIFO(type))
		ft_putchar('p');
	ft_perm(elem);
}

void			display_l_wrapper(t_file *elem, int opts)
{
	char	buf[PATH_MAX + 1];
	ssize_t	n;
	char	*fullpath;
	int		malloced;

	malloced = 0;
	ft_typenperm(elem);
	if (S_ISLNK(elem->stat.st_mode))
	{
		fullpath = ft_check_paths(elem, opts, &malloced);
		if ((n = readlink(fullpath, buf, PATH_MAX)) != -1)
		{
			buf[n] = '\0';
			ft_putstr(elem->name);
			ft_putstr(" -> ");
			ft_putendl(buf);
		}
		else
			ft_error(errno, elem->name);
		if (malloced)
			ft_strdel(&fullpath);
	}
	else
		ft_putendl(elem->name);
}
