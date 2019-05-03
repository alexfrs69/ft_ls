/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:20:40 by afrancoi          #+#    #+#             */
/*   Updated: 2019/04/24 04:47:53 by afrancoi         ###   ########.fr       */
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
	int			indexpow;

	indexpow = 0;
	listoptions = 0;
	aci = 1;
	while (aci < argc)
	{
		avi = 0;
		while(argv[aci][avi])
		{
			if(argv[aci][avi] == '-' && argv[aci][++avi])
			{
				while (argv[aci][avi])
				{
					if (argv[aci][avi] && ft_strchr(str, argv[aci][avi]))
					{
						indexpow = (int)ft_pow(2, ft_strichr(str, argv[aci][avi++]));
						if(!(listoptions & indexpow))
							listoptions += indexpow;
						*decal += 1;
					}
					else
					{
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
