/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize97.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:06:27 by suchua            #+#    #+#             */
/*   Updated: 2023/05/07 02:51:48 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_stack **a, int num)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 1;
	while (tmp->val != num)
	{
		if (tmp->val > num)
			tmp->pos++;
		else
			i++;
		tmp = tmp->next;
	}
	tmp->pos = i;
}

void	normalize97(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a);
	while (tmp)
	{
		set_pos(a, tmp->pos);
		tmp = tmp->next;
	}
}
