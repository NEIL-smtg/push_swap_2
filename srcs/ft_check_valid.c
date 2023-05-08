/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:46:09 by suchua            #+#    #+#             */
/*   Updated: 2022/11/15 14:56:13 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	good_str(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ft_is_nb(&s[i]))
		i++;
	if (!s[i])
		return (1);
	return (0);
}

t_stack	*more_than_2av(char **av)
{
	long	num;
	int		i;
	t_stack	*s;

	i = 0;
	s = NULL;
	while (av[++i])
	{
		num = my_atoi(av[i], s);
		if (!good_str(av[i]) || !check_range(num) || check_dup(&s, num))
			clear_and_exit(s);
		stack_add_back(&s, ft_newstack(num));
	}
	if (get_stack_size(s) <= 1)
		clear_and_exit(s);
	return (s);
}

t_stack	*break_down_av(char *str)
{
	int		i;
	long	num;
	t_stack	*s;

	i = 0;
	s = NULL;
	while (ft_isspace(str[i]))
		i++;
	while (str[i])
	{
		num = my_atoi(&str[i], s);
		if (!ft_is_nb(&str[i]) || check_dup(&s, num) || !check_range(num))
			clear_and_exit(s);
		stack_add_back(&s, ft_newstack(num));
		while (ft_is_nb(&str[i]))
			i++;
		while (ft_isspace(str[i]))
			i++;
	}
	return (s);
}

t_stack	*ft_check_valid(int ac, char **av)
{
	if (ac == 2)
		return (break_down_av(av[1]));
	if (ac > 2)
		return (more_than_2av(av));
	return (NULL);
}
