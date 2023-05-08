/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_infinity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:48:36 by suchua            #+#    #+#             */
/*   Updated: 2023/05/08 03:26:54 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_pos(t_stack **s, int val)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	tmp = *s;
	while (tmp->val != val)
	{
		if (tmp->val > val)
			tmp->pos++;
		else
			++i;
		tmp = tmp->next;
	}
	tmp->pos = i;
}

static void	pre_set_position(t_stack **s)
{
	t_stack	*tmp;

	tmp = *s;
	while (tmp)
	{
		set_pos(s, tmp->val);
		tmp = tmp->next;
	}
}

static void	push_smaller_to_b(t_stack **a, t_stack **b)
{
	int		mid;
	int		size;

	size = get_stack_size(*a);
	mid = size / 2;
	while (size)
	{
		if ((*a)->pos < mid)
			pb(a, b, PRINT);
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

	lowest = MAX;
	while (s)
	{
		if (s->pos < lowest)
			lowest = s->pos;
		s = s->next;
	}
	return (lowest);
}

void	one_final_move(t_stack **a, t_stack **b, int flag, int stop)
{
	int		indices;
	int		i2;

	indices = (*a)->pos;
	while ((*a)->pos != stop)
	{
		if ((*a)->pos != indices)
			flag = 1;
		else
			indices++;
		if (flag)
		{
			i2 = (*a)->pos;
			while ((*a)->pos != stop && (*a)->pos == i2)
			{
				++i2;
				pb(a, b, PRINT);
			}
			flag = !flag;
		}
		else
			ra(a, PRINT);
	}
	while ((*a)->pos - (*b)->pos == 1)
		pa(a, b, PRINT);
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
	ft_printf("start\n");
	if (!check_sort(a))
		one_final_move(a, b, 0, get_last_elem((*a))->pos);
}
