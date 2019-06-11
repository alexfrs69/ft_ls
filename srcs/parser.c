/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:20:40 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/08 20:22:20 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static int		cacl_offset_opt(char **argv, int aci, int avi, int *listoptions)
{
	int			indexpow;
	static char	*str = "aGlRtr";

	if (argv[aci][avi] && ft_strchr(str, argv[aci][avi]))
	{
		indexpow = (int)ft_pow(2, ft_strichr(str, argv[aci][avi++]));
		if (!(*listoptions & indexpow))
			*listoptions += indexpow;
		return (1);
	}
	else
		ft_putendl("Illegal options");
	return (0);
}

int				parse_args(int argc, char **argv, int *decal)
{
	int			aci;
	int			avi;
	int			listoptions;

	listoptions = 0;
	aci = 1;
	while (aci < argc)
	{
		avi = 0;
		while (argv[aci][avi])
		{
			if (argv[aci][avi] == '-' && argv[aci][avi + 1] != '-')
			{
				while (argv[aci][++avi])
					if (!cacl_offset_opt(argv, aci, avi, &listoptions))
						exit(1);
				++*decal;
			}
			else
			{
				if (argv[aci][avi + 1] == '-')
					++*decal;
				break ;
			}
		}
		aci++;
	}
	if((argc - *decal) > 2)
		listoptions += OPTS;
	return (listoptions);
}
