/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 03:14:23 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/25 03:48:56 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <errno.h>

void	ft_error(int ernb, char *path)
{
	ft_putstr_fd(path, 2);
	ft_putendl_fd(":", 2);
	ft_putstr_fd("ft_ls: ", 2);
	path = ft_strrchr(path, '/');
	ft_putstr_fd(path + 1, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(ernb), 2);
	ft_putchar_fd('\n', 2);
}
