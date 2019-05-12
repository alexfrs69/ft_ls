/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:29:54 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/06 13:15:00 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	route_to(t_queue *queu, int listoptions)
{
	if ((listoptions & OPT_R))
		options_recursive(queu, listoptions);
	else
		queue_file(queu, listoptions);
}
