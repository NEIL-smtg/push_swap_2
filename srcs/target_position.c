/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 04:03:46 by suchua            #+#    #+#             */
/*   Updated: 2023/05/08 02:35:56 by suchua           ###   ########.fr       */
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

int	switch_target(t_stack **a, int bpos)
{
	int		needle;
	t_stack	*tmpa;
	
	needle = bpos;
	while (--needle >= 1)
	{
		tmpa = *a;
		while (tmpa)
		{
			if (tmpa->pos == needle)
				return (tmpa->step);
			tmpa = tmpa->next;
		}
	}
	return (0);
}

int	get_target(t_stack **a, int bpos, int b_size)
{
	int		needle;
	int		size;
	t_stack	*tmpa;
	
	size = get_stack_size(*a) + b_size;
	needle = bpos;
	while (++needle <= size)
	{
		tmpa = *a;
		while (tmpa)
		{
			if (tmpa->pos == needle)
				return (tmpa->step);
			tmpa = tmpa->next;
		}
	}
	return (0);
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
		tmpb->a_highest = 0;
		tmpb->a_lowest = 0;
		if (tmpb->pos < min)
		{
			tmpb->target_pos = 0;
			tmpb->a_lowest = 1;
		}
		else if (tmpb->pos > max)
		{
			tmpb->a_highest = 1;
			tmpb->target_pos = 1;
		}
		else
			tmpb->target_pos = get_target(a, tmpb->pos, get_stack_size(*b));
		tmpb = tmpb->next;
	}
}
