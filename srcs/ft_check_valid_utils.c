/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:09:58 by suchua            #+#    #+#             */
/*   Updated: 2023/05/07 02:40:45 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_and_exit(t_stack *s)
{
	ft_clear_stack(&s);
	exit_now();
}

int	ft_isspace(char ch)
{
	return ((ch >= 9 && ch <= 13) || ch == 32);
}

void	exit_now(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	check_range(long num)
{
	return (num >= -2147483648 && num <= 2147483647);
}

int	check_dup(t_stack **a, int num)
{
	t_stack	*tmp;

	tmp = (*a);
	while (tmp)
	{
		if (tmp->val == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
