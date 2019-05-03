/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:09:01 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/03 15:38:55 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static int recur_queue_file(t_queue *queue, t_file *start)
{


void	options_recursive(t_queue *queue, int listoptions)
{
	t_file *start;

	listoptions = 0;
	start = get_start_node();
	recur_queue_file(queue, start);
	display_list(start);
}
