/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:25:41 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/06/10 15:22:11 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *arg)
{
	int		i;
	long	nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (arg[i] == ' ' || (arg[i] > 8 && arg[i] < 14))
		i++;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			neg = -1;
		i++;
	}
	while (arg[i] && (arg[i] >= '0' && arg[i] <= '9'))
	{
		nb = nb * 10 + (arg[i] - '0');
		i++;
	}
	return (nb * neg);
}


int ft_max(int a, int b)
{
	if(a > b)
		return(a);
	return(b);
}

int ft_min(int a, int b)
{
	if(a < b)
		return(a);
	return(b);
}
