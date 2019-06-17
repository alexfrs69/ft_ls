/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:20:40 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/17 03:53:39 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static int		cacl_offset_opt(char **argv, int aci, int avi, int *listoptions)
{
	int			indexpow;
	static char	*str = "alRtr";

	if (argv[aci][avi] && ft_strchr(str, argv[aci][avi]))
	{
		indexpow = (int)ft_pow(2, ft_strichr(str, argv[aci][avi++]));
		if (!(*listoptions & indexpow))
			*listoptions += indexpow;
		return (1);
	}
	else
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(argv[aci][avi]);
		ft_putchar('\n');
		ft_putstr("usage: ft_ls [-");
		ft_putstr(str);
		ft_putendl("] [file ...]");
		return (0);
	}
}

static	int		ft_check(int aci, char **argv, int *listoptions)
{
	int avi;
	int ret;

	ret = 0;
	avi = 0;
	while (argv[aci][avi])
	{
		if (argv[aci][avi] == '-' && argv[aci][avi + 1] != '-')
		{
			while (argv[aci][++avi])
				if (!cacl_offset_opt(argv, aci, avi, listoptions))
					exit(1);
			++ret;
		}
		else
		{
			argv[aci][avi + 1] == '-' ? ++ret : 0;
			break ;
		}
	}
	return (ret);
}

int				parse_args(int argc, char **argv, int *decal)
{
	int			aci;
	int			listoptions;

	listoptions = 0;
	aci = 0;
	while (++aci < argc)
		*decal += ft_check(aci, argv, &listoptions);
	if ((argc - *decal) > 2)
		listoptions += OPTS;
	return (listoptions);
}
