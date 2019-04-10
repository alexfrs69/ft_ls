/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:20:40 by afrancoi          #+#    #+#             */
/*   Updated: 2019/04/10 17:25:44 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int parse_args(int argc, char **argv)
{
	int aci;
	int avi;
	int listoptions;
	static char *str = "aGlR";

	listoptions = 0;
	aci = 1;
	while (aci < argc)
	{
		avi = 0;
		while(argv[aci][avi])
		{
			if(argv[aci][avi] == '-' && argv[aci][++avi])
			{
				printf("Detected arguments start at %d\n", avi);
				while (argv[aci][avi++])
				{
					if (ft_strchr(str, argv[aci][avi]))
						listoptions += (int)ft_pow(2, ft_strichr(str, argv[aci][avi]));
					else
					{
						printf("Options %c does not exist in < %s >\n", argv[aci][avi], str);
						ft_putendl("Illegal options");
						exit(1);
					}
				}
			}
			else
				break ;
		}
		aci++;
	}
	return (listoptions);
}
