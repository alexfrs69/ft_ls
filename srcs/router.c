/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:29:54 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/03 19:03:45 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	route_to(t_file *list, int listopts)
{
	if ((listopts & OPT_R))
		options_recursive(list, listopts);
	else
		save_list_dir(list, listopts);
}
