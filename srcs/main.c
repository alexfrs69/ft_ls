/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:13:08 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/17 03:56:33 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void	ft_kickstart(int argc, char **argv)
{
	int		i;
	int		listopt;
	int		decal;
	t_stat	stat;
	t_file	*list;

	decal = 0;
	listopt = parse_args(argc, argv, &decal);
	list = NULL;
	if ((argc - decal) == 1)
		save_dir(".", listopt);
	else
	{
		i = (decal ? decal : 0);
		while (++i < argc)
		{
			if (!lstat(argv[i], &stat))
				list = init_node(list, NULL, &stat, argv[i]);
			else
				printf("ft_ls: %s: no such file or directory\n", argv[i]);
		}
		route_to(list, listopt);
	}
}

int			main(int argc, char **argv)
{
	ft_kickstart(argc, argv);
	return (0);
}
