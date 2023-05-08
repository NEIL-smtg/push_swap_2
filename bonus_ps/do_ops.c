/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:35:02 by suchua            #+#    #+#             */
/*   Updated: 2022/12/05 15:51:17 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	handle_rrr(t_stack **a, t_stack **b)
{
	if (*a && *b)
		rrr(a, b, 0);
	else if (*a)
		rra(a, 0);
	else if (*b)
		rrb(b, 0);
}

void	handle_rr(t_stack **a, t_stack **b)
{
	if (*a && *b)
		rr(a, b, 0);
	else if (*a)
		ra(a, 0);
	else if (*b)
		rb(b, 0);
}

void	handle_ss(t_stack **a, t_stack **b)
{
	if (get_stack_size(*a) >= 2 && get_stack_size(*b) >= 2)
		ss(a, b, 0);
	else if (get_stack_size(*a) >= 2)
		sa(a, 0);
	else if (get_stack_size(*b) >= 2)
		sb(b, 0);
}

void	do_ops(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(op, "pa", 3) && *b)
		pa(a, b, 0);
	else if (!ft_strncmp(op, "pb", 3) && *a)
		pb(a, b, 0);
	else if (!ft_strncmp(op, "rra", 4) && *a)
		rra(a, 0);
	else if (!ft_strncmp(op, "rrb", 4) && *b)
		rrb(b, 0);
	else if (!ft_strncmp(op, "rrr", 4))
		handle_rrr(a, b);
	else if (!ft_strncmp(op, "ra", 3) && *a)
		ra(a, 0);
	else if (!ft_strncmp(op, "rb", 3) && *b)
		ra(a, 0);
	else if (!ft_strncmp(op, "rr", 3))
		handle_rr(a, b);
	else if (!ft_strncmp(op, "sa", 3) && get_stack_size(*a) >= 2)
		sa(a, 0);
	else if (!ft_strncmp(op, "sb", 3) && get_stack_size(*b) >= 2)
		sb(b, 0);
	else if (!ft_strncmp(op, "ss", 3))
		handle_ss(a, b);
}
