/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:13:08 by afrancoi          #+#    #+#             */
/*   Updated: 2019/04/10 16:55:14 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int i;
	int listopt;

	listopt = parse_args(argc, argv);
	printf("Argc = %d | List opt = %d\n", argc, listopt);

	if (argc == 1)
		save_file(".");
	else
	{
		i = 0;
		while (++i < argc)
		{
			if (!save_file(argv[1]))
			{
				ft_putstr("ft_ls: ");
				ft_putstr(argv[i]);
				ft_putendl(": No such file or directory");
				return (1);
			}
		}
	}
	display_list(get_start_node());
	return (0);
}



