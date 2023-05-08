/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:16:25 by suchua            #+#    #+#             */
/*   Updated: 2023/05/08 00:43:10 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_is_nb(char *s)
{
	return (ft_isdigit(*s) || (ft_is_sign(*s) && ft_isdigit(s[1])));
}

int	ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	return (-nb);
}
