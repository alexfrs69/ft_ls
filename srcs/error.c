/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 03:14:23 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/25 11:00:58 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <errno.h>

void	ft_error(int ernb, char *path)
{
	char *tmp;

	if((tmp = ft_strrchr(path, '/')))
		tmp++;
	else
		tmp = path;
	ft_putstr_fd(path, 2);
	ft_putendl_fd(":", 2);
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(tmp, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(ernb), 2);
}
