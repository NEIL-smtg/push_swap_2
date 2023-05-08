/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 04:03:46 by suchua            #+#    #+#             */
/*   Updated: 2023/05/08 19:51:38 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_highest_pos(t_stack *a)
{
	int	max;

	max = 0;
	while (a)
	{
		if (a->pos > max)
			max = a->pos;
		a = a->next;
	}
	return (max);
}

int	get_lowest_pos(t_stack *a)
{
	int	min;

	min = MAX;
	while (a)
	{
		if (a->pos < min)
			min = a->pos;
		a = a->next;
	}
	return (min);
}

static int	get_target(t_stack **a, int bpos, int t1, int t2)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->pos > bpos && tmp_a->pos < t1)
		{
			t1 = tmp_a->pos;
			t2 = tmp_a->step;
		}
		tmp_a = tmp_a->next;
	}
	if (t1 != MAX)
		return (t2);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->pos < t1)
		{
			t1 = tmp_a->pos;
			t2 = tmp_a->step;
		}
		tmp_a = tmp_a->next;
	}
	return (t2);
}

void	set_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmpb;
	int		min;
	int		max;

	tmpb = *b;
	min = get_lowest_pos(*a);
	max = get_highest_pos(*a);
	while (tmpb)
	{
		tmpb->target_pos = get_target(a, tmpb->pos, MAX, 0);
		tmpb = tmpb->next;
	}
}
