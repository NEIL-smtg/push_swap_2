/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:18:30 by suchua            #+#    #+#             */
/*   Updated: 2023/05/08 20:27:15 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	get_rid_of_nl(char *ops)
{
	int	len;

	len = ft_strlen(ops) - 1;
	if (ops[len] == '\n')
		ops[len] = 0;
}

void	get_input(t_stack **a, t_stack **b)
{
	char	*ops;

	while (1)
	{
		ops = get_next_line(STDIN);
		if (!ops)
			break ;
		get_rid_of_nl(ops);
		check_ops(ops, a, b);
		do_ops(ops, a, b);
		free(ops);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		stack_a = ft_check_valid(ac, av);
		get_input(&stack_a, &stack_b);
		show_result(&stack_a, &stack_b);
		ft_clear_stack(&stack_a);
		ft_clear_stack(&stack_b);
	}
	return (0);
}
