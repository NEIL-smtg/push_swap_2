/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:01:41 by suchua            #+#    #+#             */
/*   Updated: 2022/11/18 16:01:41 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_from_bottom(t_stack **a, t_stack **b)
{
	int	n;

	n = 0;
	while ((get_last_elem(*a))->val > (*b)->val)
	{
		rra(a, PRINT);
		n++;
	}
	pa(a, b, PRINT);
	n++;
	if ((*b) && (*b)->val > get_last_elem(*a)->val && (*a)->val > (*b)->val)
	{
		pa(a, b, PRINT);
		n++;
	}
	while (n--)
		ra(a, PRINT);
}

void	start_from_top(t_stack **a, t_stack **b)
{
	int	n;

	n = 0;
	while ((*a)->val < (*b)->val)
	{
		ra(a, PRINT);
		n++;
	}
	pa(a, b, PRINT);
	while (n--)
		rra(a, PRINT);
}

void	ft_push_somewhere(t_stack **a, t_stack **b)
{
	if ((*b)->val > (get_mid_stk(*a))->val)
		start_from_bottom(a, b);
	else
		start_from_top(a, b);
}

int	ft_handle_bnext(t_stack **a, t_stack **b, t_stack *last)
{
	t_stack	*bnext;

	bnext = (*b)->next;
	if (bnext->val < (*a)->val)
	{
		sb(b, PRINT);
		pa(a, b, PRINT);
		return (1);
	}
	else if (bnext->val > last->val)
	{
		sb(b, PRINT);
		pa(a, b, PRINT);
		ra(a, PRINT);
		return (1);
	}
	return (0);
}

void	ft_sort5(t_stack **a, t_stack **b)
{
	t_stack	*last;

	while (*b)
	{
		last = get_last_elem(*a);
		if ((*b)->val > last->val)
		{
			pa(a, b, PRINT);
			ra(a, PRINT);
		}
		else if ((*b)->val < (*a)->val)
			pa(a, b, PRINT);
		else if ((*b)->next && !ft_handle_bnext(a, b, last))
			ft_push_somewhere(a, b);
		else
			ft_push_somewhere(a, b);
	}
}
