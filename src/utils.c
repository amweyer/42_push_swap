/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:25:41 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/06/07 16:57:28 by amweyer          ###   ########.fr       */
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

void	add_node(t_stack **a, int n)
{
	t_stack	*new_block;
	t_stack	*tmp;

	new_block = malloc(sizeof(t_stack));
	if (!a || !new_block)
		return ;
	new_block->nb = n;
	new_block->index = 0;
	new_block->next = NULL;
	new_block->prev = NULL;
	if (!*a)
		*a = new_block;
	else
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_block;
		new_block->prev = tmp;
	}
}

void	show_nodes(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_printf("%d\n", stack->nb);
		stack = stack->next;
	}
}