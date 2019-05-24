/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:13:08 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/25 01:27:55 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void	ft_kickstart(int argc, char **argv)
{
	int		i;
	int		listopt;
	int		decal;
	t_queue	*queue;
	t_stat	stat;

	decal = 0;
	queue = NULL;
	listopt = parse_args(argc, argv, &decal);
	if ((argc - decal) == 1)
		route_to(queue_add(NULL, "."), listopt);
	else
	{
		i = (decal ? decal : 0);
		while (++i < argc)
		{
			if (!lstat(argv[i], &stat))
				queue = init_queue(queue, argv[i]);
			else
				printf("ft_ls: %s no such file or directory\n", argv[i]);
		}
		route_to(queue, listopt);
	}
}

int			main(int argc, char **argv)
{
	ft_kickstart(argc, argv);
	return (0);
}
