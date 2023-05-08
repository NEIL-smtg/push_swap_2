/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:30:34 by suchua            #+#    #+#             */
/*   Updated: 2022/12/05 15:40:33 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_ko(void)
{
	ft_putendl_fd("KO", 1);
}

void	print_ok(void)
{
	ft_putendl_fd("OK", 1);
}

void	show_result(t_stack **a, t_stack **b)
{
	if (*b || !check_sort(a))
		print_ko();
	else
		print_ok();
}
