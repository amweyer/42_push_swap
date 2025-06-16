/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:21:28 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/16 15:58:36 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	get_cost(t_stack *node)
{
	int	cost_a;
	int	cost_b;
	int	cost;

	cost = 1;
	if (!node->above_median)
		cost_a = node->index;
	else
		cost_a = node->size - node->index;
	if (!node->target_node->above_median)
		cost_b = node->target_node->index;
	else
		cost_b = node->target_node->size - node->target_node->index;

	DEBUG_PRINT(" cost a: %d, target: %d, ndex: %d, cost b: %d\n", cost_a, node->target_node->nb, node->target_node->index,cost_b);

	if ((node->target_node->above_median && !node->above_median)
		|| !(node->target_node->above_median && node->above_median))
		cost += cost_a + cost_b;
	else
		cost += ft_max(cost_a, cost_b);
	return (cost);
}


void	update_cost(t_stack **a, t_stack **b)
{
	t_stack	*current_node;

	update_index(a);
	update_index(b);
	update_median(a);
	update_median(b);
	update_stack_size(a);
	update_stack_size(b);
	current_node = *a;
	while (current_node)
	{
		current_node->cost = get_cost(current_node);
		DEBUG_PRINT("node:%d, index: %d, cost:%d, target:%d\n", current_node->nb, current_node->index, current_node->cost, current_node->target_node->nb);
		current_node = current_node->next;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	int		cheapest;
	t_stack	*cheapest_node;

	cheapest = stack->cost;
	cheapest_node = stack;
	while (stack)
	{
		if (stack->cost < cheapest)
		{
			cheapest = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}
