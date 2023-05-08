/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:25:12 by suchua            #+#    #+#             */
/*   Updated: 2022/11/15 18:56:29 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	ft_printf("%6c\t%14c\n", 'a', 'b');
	while (1)
	{
		if (!a && !b)
			return ;
		if (a)
			ft_printf("|%11d  |\t|", a->pos);
		else
			ft_printf("|%11c  |\t|", 'n');
		if (b)
			ft_printf("%11d  |\n", b->pos);
		else
			ft_printf("%11c  |\n", 'n', 'n');
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		a = ft_check_valid(ac, av);
		ft_sort(&a, &b);
		print_stack(a, b);
		ft_clear_stack(&a);
		ft_clear_stack(&b);
	}
	exit (0);
}
