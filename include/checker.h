/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:19:24 by suchua            #+#    #+#             */
/*   Updated: 2023/05/08 20:07:55 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../Libft/libft.h"
# include "push_swap.h"
# define STDIN 0

//everthing about ops
void	check_ops(char *op, t_stack **a, t_stack **b);
void	do_ops(char *op, t_stack **a, t_stack **b);

//show result KO OK
void	show_result(t_stack **a, t_stack **b);

void	free_everything(char *ops, t_stack **a, t_stack **b);

#endif