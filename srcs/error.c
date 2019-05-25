/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 03:14:23 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/25 03:35:39 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <errno.h>

void	ft_error(int ernb, char *path)
{
	ft_putstr(path);
	ft_putendl(":");
	ft_putstr("ft_ls: ");
	path = ft_strrchr(path, '/');
	ft_putstr(path + 1);
	ft_putstr(": ");
	ft_putendl(strerror(ernb));
	ft_putchar('\n');
}
