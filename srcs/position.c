/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:56:45 by suchua            #+#    #+#             */
/*   Updated: 2023/05/08 19:57:24 by suchua           ###   ########.fr       */
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

void	pre_set_position(t_stack **s)
{
	t_stack	*tmp;

	tmp = *s;
	while (tmp)
	{
		set_pos(s, tmp->val);
		tmp = tmp->next;
	}
}
