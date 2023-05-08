/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:46:47 by suchua            #+#    #+#             */
/*   Updated: 2022/12/05 15:47:09 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_everything(char *ops, t_stack **a, t_stack **b)
{
	free(ops);
	ft_clear_stack(a);
	ft_clear_stack(b);
	ops = NULL;
	exit_now();
}
