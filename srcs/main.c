/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:13:08 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/08 01:05:52 by afrancoi         ###   ########.fr       */
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

	decal = 0;
	listopt = parse_args(argc, argv, &decal);
	if ((argc - decal) == 1)
		save_file(".", get_start_node());
	else
	{
		queue = get_queue_node();
		i = (decal ? decal : 0);
		queue_fill(queue, argv[++i]);
		while (++i < argc)
			queue_add(queue, argv[i]);
		route_to(queue, listopt);
	}
	return (0);
}



