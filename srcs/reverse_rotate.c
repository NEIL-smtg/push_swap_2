/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:49:18 by suchua            #+#    #+#             */
/*   Updated: 2023/05/07 20:58:04 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int print)
{
	t_stack	*new;
	t_stack	*last;
	t_stack	*pre;

	if (!a || !*a || get_stack_size(*a) <= 1)
		return ;
	new = get_dup_stack(get_last_elem(*a));
	new->next = *a;
	last = *a;
	while (last->next)
	{
		pre = last;
		last = last->next;
	}
	free(last);
	pre->next = NULL;
	*a = new;
	if (print)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **b, int print)
{
	t_stack	*new;
	t_stack	*last;
	t_stack	*pre;

	if (!b || !*b || get_stack_size(*b) <= 1)
		return ;
	new = get_dup_stack(get_last_elem(*b));
	new->next = *b;
	last = *b;
	while (last->next)
	{
		pre = last;
		last = last->next;
	}
	free(last);
	pre->next = NULL;
	*b = new;
	if (print)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		ft_putendl_fd("rrr", 1);
}
