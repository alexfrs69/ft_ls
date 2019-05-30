/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 06:43:47 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/30 12:48:12 by root             ###   ########.fr       */
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

static t_file	*sortedmerge(t_file *a, t_file *b, t_cmp cmp)
{
	t_file *res;

	res = NULL;
	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (cmp(a, b))
	{
		res = a;
		res->next = sortedmerge(a->next, b, cmp);
	}
	else
	{
		res = b;
		res->next = sortedmerge(a, b->next, cmp);
	}
	return (res);
}

static t_cmp ft_getcmp(int opts)
{
	if (opts & OPT_T)
		return (&check_time);
	else
		return (&check_strcmp);
}

void			ft_mergesort_tfile(t_file **start, int opts)
{
	t_file *a;
	t_file *b;
	t_file *head;

	head = *start;
	if (!head || !head->next)
		return ;
	split_list(head, &a, &b);
	ft_mergesort_tfile(&a, opts);
	ft_mergesort_tfile(&b, opts);
	*start = sortedmerge(a, b, *ft_getcmp(opts));
}
