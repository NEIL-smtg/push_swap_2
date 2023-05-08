/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:49:08 by suchua            #+#    #+#             */
/*   Updated: 2023/05/07 23:22:16 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int print)
{
	t_stack	*tmp;

	if (get_stack_size(*a) <= 1)
		return ;
	tmp = (*a)->next;
	stack_add_back(a, get_dup_stack(*a));
	free(*a);
	*a = tmp;
	if (print)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack **b, int print)
{
	t_stack	*tmp;

	if (get_stack_size(*b) <= 1)
		return ;
	tmp = (*b)->next;
	stack_add_back(b, get_dup_stack(*b));
	free(*b);
	*b = tmp;
	if (print)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_putendl_fd("rr", 1);
}
