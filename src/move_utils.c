/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:52:23 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/13 12:54:37 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move(t_stack **a, t_stack **b)
{
    int index_b;
	int index_a;

	t_stack *cheapest_node;

	
	cheapest_node = get_cheapest(*a);
	index_a = cheapest_node->index;
	index_b = cheapest_node->target_node->index;

	DEBUG_PRINT("cheapest_node: %d\n", cheapest_node->nb);

	if(!cheapest_node->above_median)
	{
		DEBUG_PRINT("target noed: %d index: %d\n", cheapest_node->target_node->nb, cheapest_node->target_node->index);

		if(cheapest_node->target_node->above_median)
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
		DEBUG_PRINT("nb b: %d", cheapest_node->nb);

		DEBUG_PRINT("index b: %d", index_b);
		index_b = cheapest_node->size - index_b + 1;
		DEBUG_PRINT("size b: %d", cheapest_node->size);
		DEBUG_PRINT("index b: %d", index_b);

		if(!cheapest_node->target_node->above_median)
		{
			while(index_b)
			{
				rb(b);
				index_b--;
			}
		}
		else
			index_a = cheapest_node->size - index_a;
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
