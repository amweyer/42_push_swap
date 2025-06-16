/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:38:07 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/16 17:45:38 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_closest(t_stack *node, t_stack **stack)
{
	long long	diff;
	long long	min_diff;
	bool		found;
	t_stack		*current_node;

	current_node = *stack;
	found = 0;
	min_diff = INT_MAX - INT_MIN;
	while (current_node)
	{
		diff = node->nb - current_node->nb;
		// printf("diff:%lld min_diff :%lld \n", diff, min_diff);
		if (min_diff > diff && diff > 0)
		{
			node->target_node = current_node;
			min_diff = diff;
			found = 1;
		}
		current_node = current_node->next;
	}
	if (!found)
		node->target_node = get_max_node(*stack);
}

void	set_target(t_stack **a, t_stack **b)
{
	t_stack	*current_node;

	current_node = *a;
	while (current_node)
	{
		get_closest(current_node, b);
		// DEBUG_PRINT("node:%d target :%d \n", current_node->nb,
			//current_node->target_node->nb);
		current_node = current_node->next;
	}
}

void	update_index(t_stack **stack)
{
	int		index;
	t_stack	*currrent_node;

	index = 0;
	currrent_node = *stack;
	while (currrent_node)
	{
		currrent_node->index = index;
		index++;
		currrent_node = currrent_node->next;
	}
}

int	get_median(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	//DEBUG_PRINT("get_stack_size(stack): %d\n", stack->size);
	if(i%2==1)
		return(i/2+1);
	return (i/2);
}

void	update_median(t_stack **stack)
{
	t_stack	*current_node;
	int		median;

	median = get_median(*stack);
	// DEBUG_PRINT("median:%d", median);

	current_node = *stack;
	while (current_node)
	{
		// DEBUG_PRINT("current_node->index  :%d \n", current_node->index );
		if (current_node->index < median)
			current_node->above_median = false;
		else
			current_node->above_median = true;
		DEBUG_PRINT("MEDIAN : node:%d above median :%d \n", current_node->nb, current_node->above_median);
		current_node = current_node->next;
	}
	// DEBUG_PRINT("END");
}

