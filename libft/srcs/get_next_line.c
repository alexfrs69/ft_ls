/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:21:49 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/28 13:17:29 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_save	*find_list(t_save **save, int fd)
{
	t_save *tmp;

	tmp = *save;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_save*)malloc(sizeof(t_save))))
		return (0);
	if (!(tmp->str = ft_strnew(0)))
	{
		free(tmp);
		return (0);
	}
	tmp->fd = fd;
	tmp->next = *save;
	*save = tmp;
	return (tmp);
}

static	int		ft_read(t_save **elem)
{
	char		*buffer;
	char		*tmp;
	int			rd;

	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((rd = read((*elem)->fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		tmp = ((*elem)->str) ? (*elem)->str : NULL;
		if (!((*elem)->str = ft_strjoin((*elem)->str, buffer)))
			return (-1);
		if (tmp)
			ft_strdel(&tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	ft_strdel(&buffer);
	return (rd);
}

static	int		ft_getnl(t_save **elem, char **line)
{
	char	*tmp;

	if ((*elem)->str && (*elem)->str[0])
	{
		if ((tmp = ft_strchr((*elem)->str, '\n')))
		{
			if (!(*line = ft_strndup((*elem)->str, tmp - (*elem)->str)))
				return (-1);
			if (!(tmp = ft_strdup((*elem)->str + (tmp - (*elem)->str) + 1)))
				return (-1);
			ft_strdel(&(*elem)->str);
			(*elem)->str = tmp;
			if ((*elem)->str[0] == '\0')
				return (2);
			return (1);
		}
		else
		{
			if (!(*line = ft_strdup((*elem)->str)))
				return (-1);
			return (2);
		}
	}
	*line = NULL;
	return (0);
}

static	void	ft_linkdel(t_save **save, t_save **elem)
{
	t_save	*prev;

	if (*elem == *save)
		*save = (*save)->next;
	else
	{
		prev = *save;
		while (prev->next != *elem && prev->next)
			prev = prev->next;
		if (prev->next == *elem)
			prev->next = (*elem)->next;
	}
	ft_strdel(&(*elem)->str);
	free(*elem);
	*elem = NULL;
}

int				get_next_line(const int fd, char **line)
{
	static t_save	*save = NULL;
	t_save			*elem;
	int				rd;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!(elem = find_list(&save, fd)))
		return (-1);
	if ((rd = ft_read(&elem)) == -1)
		return (-1);
	if (rd == 0 && !ft_strlen(elem->str))
	{
		ft_linkdel(&save, &elem);
		return (0);
	}
	if ((ret = ft_getnl(&elem, line)) == 2)
	{
		ft_linkdel(&save, &elem);
		return (1);
	}
	return (ret);
}
