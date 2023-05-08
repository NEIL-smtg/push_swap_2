/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 04:39:48 by suchua            #+#    #+#             */
/*   Updated: 2023/05/08 01:29:09 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_cost *cost)
{
	while (cost->cost_a > 0 && cost->cost_b > 0)
	{
		rr(a, b, PRINT);
		cost->cost_a--;
		cost->cost_b--;
	}
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_cost *cost)
{
	while (cost->cost_a < 0 && cost->cost_b < 0)
	{
		rrr(a, b, PRINT);
		cost->cost_a++;
		cost->cost_b++;
	}
}

void	rotate_a(t_stack **a, int cost_a)
{
	if (cost_a < 0)
	{
		while (cost_a < 0)
		{
			cost_a++;
			rra(a, PRINT);
		}
	}
	else
	{
		while (cost_a > 0)
		{
			cost_a--;
			ra(a, PRINT);
		}
	}
}

void	rotate_b(t_stack **b, int cost_b)
{
	if (cost_b < 0)
	{
		while (cost_b < 0)
		{
			cost_b++;
			rrb(b, PRINT);
		}
	}
	else
	{
		while (cost_b > 0)
		{
			cost_b--;
			rb(b, PRINT);
		}
	}
}

void	execute(t_stack **a, t_stack **b, t_cost *cost)
{
	if (cost->a_highest)
	{
		rotate_b(b, cost->cost_b);
		pa(a, b, PRINT);
		ra(a, PRINT);
		return ;
	}
	else if (cost->a_lowest)
	{
		rotate_b(b, cost->cost_b);
		pa(a, b, PRINT);
		return ;
	}
	rev_rotate_both(a, b, cost);
	rotate_both(a, b, cost);
	rotate_a(a, cost->cost_a);
	rotate_b(b, cost->cost_b);
	pa(a, b, PRINT);
}
