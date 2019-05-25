/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tqueue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 08:40:13 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/25 08:43:15 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void		split_list(t_queue *start, t_queue **a, t_queue **b)
{
	t_queue *slow;
	t_queue *fast;

	slow = start;
	fast = start->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = start;
	*b = slow->next;
	slow->next = NULL;
}

static t_queue	*sortedmerge(t_queue *a, t_queue *b)
{
	t_queue *result;

	result = NULL;
	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (ft_strcmp(a->path, b->path) < 0)
	{
		result = a;
		result->next = sortedmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b->next);
	}
	return (result);
}

void		ft_mergesort_tqueue(t_queue **start)
{
	t_queue *a;
	t_queue *b;
	t_queue *head;

	head = *start;
	if (!head || !head->next)
		return ;
	split_list(head, &a, &b);
	ft_mergesort_tqueue(&a);
	ft_mergesort_tqueue(&b);
	*start = sortedmerge(a, b);
}
