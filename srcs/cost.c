/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 04:31:10 by suchua            #+#    #+#             */
/*   Updated: 2023/05/08 19:54:00 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_cost(t_cost *cost, t_stack *tmpb)
{
	cost->cost_a = tmpb->cost_a;
	cost->cost_b = tmpb->cost_b;
	cost->cheapest = tmpb->cost_a + tmpb->cost_b;
}

void	execute_cheapest_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmpb;
	t_cost	cost;

	tmpb = *b;
	cost.cheapest = MAX;
	while (tmpb)
	{
		if (ft_abs(tmpb->cost_a) + ft_abs(tmpb->cost_b) < ft_abs(cost.cheapest))
			init_cost(&cost, tmpb);
		tmpb = tmpb->next;
	}
	execute(a, b, &cost);
}

void	set_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmpb;
	int		size_a;
	int		size_b;

	tmpb = *b;
	size_b = get_stack_size(*b);
	size_a = get_stack_size(*a);
	while (tmpb)
	{
		tmpb->cost_a = tmpb->target_pos;
		tmpb->cost_b = tmpb->step;
		if (tmpb->cost_a >= size_a / 2)
			tmpb->cost_a = tmpb->cost_a - size_a;
		if (tmpb->cost_b >= size_b / 2)
			tmpb->cost_b = tmpb->cost_b - size_b;
		tmpb = tmpb->next;
	}
}
