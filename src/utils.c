/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:25:41 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/06/08 13:08:47 by amweyer          ###   ########.fr       */
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

int	get_stack_size(t_stack *stack)
{
	int	nb;

	nb = 0;
	while (stack)
	{
		stack = stack->next;
		nb++;
	}
	return (nb);
}

t_stack	*get_max_node(t_stack *stack)
{
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->nb > max_node->nb)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*get_min_node(t_stack *stack)
{
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->nb < min_node->nb)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

