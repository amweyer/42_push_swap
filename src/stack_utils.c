/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:35:42 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/10 14:53:42 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	update_stack_size(t_stack **stack)
{
	int		stack_size;
	t_stack	*current;

	stack_size = get_stack_size(*stack);
	current = *stack;
	while (current)
	{
		current->size = stack_size;
		current = current->next;
	}
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
	t_stack *min_node;

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