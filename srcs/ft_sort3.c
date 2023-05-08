/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 01:39:38 by suchua            #+#    #+#             */
/*   Updated: 2022/11/15 14:42:09 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_handle_swap(t_stack **s, int type)
{
	if (type == TYPE_A)
		sa(s, PRINT);
	else
		sb(s, PRINT);
}

void	ft_handle_rr(t_stack **s, int type)
{
	if (type == TYPE_A)
		rra(s, PRINT);
	else
		rrb(s, PRINT);
}

void	ft_handle_r(t_stack **s, int type)
{
	if (type == TYPE_A)
		ra(s, PRINT);
	else
		rb(s, PRINT);
}

void	ft_sort3(t_stack **s, int type)
{
	t_stack	*first;
	t_stack	*sec;
	t_stack	*third;
	int		stk_size;

	stk_size = get_stack_size(*s);
	while (!check_sort(s))
	{
		first = *s;
		sec = first->next;
		if (stk_size == 3)
			third = sec->next;
		if (third && first->val > sec->val && first->val > third->val)
			ft_handle_r(s, type);
		else if (first->val > sec->val)
			ft_handle_swap(s, type);
		else
			ft_handle_rr(s, type);
	}
}
