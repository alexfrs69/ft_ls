/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:13:08 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/19 07:41:42 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		i;
	int		listopt;
	int		decal;
	t_queue	*queue;
	t_stat	stat;

	decal = 0;
	listopt = parse_args(argc, argv, &decal);
	if ((argc - decal) == 1)
		route_to(queue_add(NULL, "."), listopt);
	else
	{
		i = (decal ? decal : 0);
		while (++i < argc)
		{
			if (!lstat(argv[i], &stat))
			{
				if (!queue)
					queue = queue_add(NULL, argv[i]);
				else
					queue_add(queue, argv[i]);
			}
			else
				printf("ft_ls: %s no such file or directory\n", argv[i]);
		}
		route_to(queue, listopt);
	}
	return (0);
}
