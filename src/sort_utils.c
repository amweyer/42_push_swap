/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:38:07 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/12 16:10:59 by amweyer          ###   ########.fr       */
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
	return (i / 2);
}

void	update_median(t_stack **stack)
{
	t_stack	*current_node;
	int		median;

	median = get_median(*stack);
	current_node = *stack;
	while (current_node)
	{
		// DEBUG_PRINT("current_node->index  :%d \n", current_node->index );
		if (current_node->index < median)
			current_node->above_median = true;
		else
			current_node->above_median = false;
		//DEBUG_PRINT("node:%d above median :%d \n", current_node->nb,
			//current_node->above_median);
		current_node = current_node->next;
	}
	// DEBUG_PRINT("END");
}

int	get_cost(t_stack *node)
{
	int	cost_a;
	int	cost_b;
	int	cost;

	cost = 1;
	if (node->above_median)
		cost_a = node->index;
	else
		cost_a = node->size - node->index;
	if (node->target_node->above_median)
		cost_b = node->target_node->index;
	else
		cost_b = node->target_node->size - node->target_node->index;
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
		//DEBUG_PRINT("node:%d cost:%d target:%d\n", current_node->nb,current_node->cost, current_node->target_node->nb);
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
		//DEBUG_PRINT("stack->cost:%d cheapest:%d\n", stack->cost, cheapest);
		if (stack->cost < cheapest)
		{
			cheapest = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

void move(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;
	int index_b;
	int index_a;

	
	cheapest_node = get_cheapest(*a);
	index_a = cheapest_node->index;
	index_b = cheapest_node->target_node->index;

	DEBUG_PRINT("cheapest_node: %d\n", cheapest_node->nb);

	if(cheapest_node->above_median)
	{
		DEBUG_PRINT("target noed: %d index: %d\n", cheapest_node->target_node->nb, cheapest_node->target_node->index);

		if(!cheapest_node->target_node->above_median)
		{
			DEBUG_PRINT("Entre if\n");
			
			while(index_b)
			{
				DEBUG_PRINT("index: %d\n", index_b);
				rrb(b);
				DEBUG_PRINT("after rrb");

				index_b--;
			}
		}
		while(index_a && index_b)
		{
			rr(a,b);
			index_a--;
			index_b--;
		}
		while(index_a)
		{
			ra(a);
			index_a--;
		}
		while(index_b)
		{
			rb(b);
			index_b--;
		}
	}
	else
	{
		if(cheapest_node->target_node->above_median)
		{
			while(index_b)
			{
				rb(b);
				index_b--;
			}
		}
		while(index_a && index_b)
		{
			rrr(a,b);
			index_a--;
			index_b--;
		}
		while(index_a)
		{
			rra(a);
			index_a--;
		}
		while(index_b)
		{
			rrb(b);
			index_b--;
		}
	}
	pb(a, b);
}
