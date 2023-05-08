/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:33:27 by suchua            #+#    #+#             */
/*   Updated: 2022/12/05 15:33:52 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_ops(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(op, "pa", 3))
		return ;
	else if (!ft_strncmp(op, "pb", 3))
		return ;
	else if (!ft_strncmp(op, "rra", 4))
		return ;
	else if (!ft_strncmp(op, "rrb", 4))
		return ;
	else if (!ft_strncmp(op, "rrr", 4))
		return ;
	else if (!ft_strncmp(op, "ra", 3))
		return ;
	else if (!ft_strncmp(op, "rb", 3))
		return ;
	else if (!ft_strncmp(op, "rr", 3))
		return ;
	else if (!ft_strncmp(op, "sa", 3))
		return ;
	else if (!ft_strncmp(op, "sb", 3))
		return ;
	else if (!ft_strncmp(op, "ss", 3))
		return ;
	else
		free_everything(op, a, b);
}
