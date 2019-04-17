/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:20:40 by afrancoi          #+#    #+#             */
/*   Updated: 2019/04/17 22:58:06 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

int parse_args(int argc, char **argv, int *decal)
{
	int			aci;
	int			avi;
	int			listoptions;
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
				//printf("args detected = %c / %d\n", argv[aci][avi], argv[aci][avi]);
				while (argv[aci][avi])
				{
					//printf("Args res = %c / %d (aci = %d | avi = %d) ichr = %d\n", argv[aci][avi], argv[aci][avi], aci, avi, ft_strichr(str, argv[aci][avi]));
					if (argv[aci][avi] && ft_strchr(str, argv[aci][avi]))
					{
					//	printf("Args finded\n");
						if(!(listoptions & (int)ft_pow(2, ft_strichr(str, argv[aci][avi]))))
							listoptions += (int)ft_pow(2, ft_strichr(str, argv[aci][avi]));
						*decal += 1;
						avi++;
					}
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
