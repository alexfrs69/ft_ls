/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:13:08 by afrancoi          #+#    #+#             */
/*   Updated: 2019/03/28 15:58:06 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		get_files(".");
	else
	{
		i = 0;
		while (++i < argc)
		{
			if(!get_files(argv[i]))
			{
				ft_putstr("ft_ls: ");
				ft_putstr(argv[i]);
				ft_putendl(": No such file or directory");
			}
		}
	}
	return (0);
}



