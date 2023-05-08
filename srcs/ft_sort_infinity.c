/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_infinity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:48:36 by suchua            #+#    #+#             */
/*   Updated: 2023/05/08 19:58:31 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_smaller_to_b(t_stack **a, t_stack **b)
{
	int		mid;
	int		size;

	size = get_stack_size(*a);
	mid = size / 3;
	while (size)
	{
		if ((*a)->pos < mid)
			pb(a, b, PRINT);
		else if ((*a)->pos < 2 * mid)
		{
			pb(a, b, PRINT);
			rb(b, PRINT);
		}
		else
			ra(a, PRINT);
		--size;
	}
	while (get_stack_size(*a) > 3)
		pb(a, b, PRINT);
}

static void	calc_step(t_stack **s)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *s;
	while (tmp)
	{
		tmp->step = i;
		++i;
		tmp = tmp->next;
	}
}

int	get_lowest_pos_in_stack(t_stack *s)
{
	int	lowest;
	int	index;

	lowest = MAX;
	while (s)
	{
		if (s->pos < lowest)
		{
			lowest = s->pos;
			index = s->step;
		}
		s = s->next;
	}
	return (index);
}

static void	one_final_move(t_stack **a)
{
	int	min;
	int	size;

	calc_step(a);
	size = get_stack_size(*a);
	min = get_lowest_pos_in_stack(*a);
	if (min >= size / 2)
	{
		while ((*a)->pos != 1)
			rra(a, PRINT);
	}
	else
	{
		while ((*a)->pos != 1)
			ra(a, PRINT);
	}
}

void	ft_sort_infinity(t_stack **a, t_stack **b)
{
	pre_set_position(a);
	push_smaller_to_b(a, b);
	ft_sort3(a, TYPE_A);
	while (*b)
	{
		calc_step(a);
		calc_step(b);
		set_target_pos(a, b);
		set_cost(a, b);
		execute_cheapest_cost(a, b);
	}
	if (!check_sort(a))
		one_final_move(a);
}
