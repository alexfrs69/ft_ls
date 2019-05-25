/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 06:43:47 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/25 08:46:44 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void		split_list(t_file *start, t_file **a, t_file **b)
{
	t_file *slow;
	t_file *fast;

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

static t_file	*sortedmerge(t_file *a, t_file *b)
{
	t_file *res;

	res = NULL;
	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (ft_strcmp(a->name, b->name) < 0)
	{
		res = a;
		res->next = sortedmerge(a->next, b);
	}
	else
	{
		res = b;
		res->next = sortedmerge(a, b->next);
	}
	return (res);
}

void			ft_mergesort_tfile(t_file **start)
{
	t_file *a;
	t_file *b;
	t_file *head;

	head = *start;
	if (!head || !head->next)
		return ;
	split_list(head, &a, &b);
	ft_mergesort_tfile(&a);
	ft_mergesort_tfile(&b);
	*start = sortedmerge(a, b);
}
