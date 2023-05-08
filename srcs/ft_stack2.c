/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:45:02 by suchua            #+#    #+#             */
/*   Updated: 2022/11/09 23:45:02 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_mid_stk(t_stack *s)
{
	int	stk_size;
	int	i;

	stk_size = get_stack_size(s) / 2;
	i = -1;
	while (++i < stk_size)
		s = s->next;
	return (s);
}

void	stack_add_front(t_stack **s, t_stack *add)
{
	if (!s || !*s)
		*s = add;
	else
	{
		add->next = *s;
		*s = add;
	}
}

void	stack_add_back(t_stack **s, t_stack *new)
{
	t_stack	*last;

	new->next = NULL;
	if (!s || !*s)
		*s = new;
	else
	{
		last = *s;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

t_stack	*get_dup_stack(t_stack *old)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->cost_a = old->cost_a;
	new->cost_b = old->cost_b;
	new->next = NULL;
	new->pos = old->pos;
	new->step = old->step;
	new->target_pos = old->target_pos;
	new->val = old->val;
	return (new);
}
