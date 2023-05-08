/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:01:07 by suchua            #+#    #+#             */
/*   Updated: 2022/11/15 14:46:25 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	my_atoi(char *str, t_stack *s)
{
	int		sign;
	int		i;
	long	total;
	int		j;

	sign = 1;
	i = 0;
	total = 0;
	j = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (j > 10)
			clear_and_exit(s);
		total = total * 10 + str[i++] - '0';
		j++;
	}
	return (total * sign);
}
