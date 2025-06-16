/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:52:23 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/16 18:14:17 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	t_stack	*target;

	cheapest = get_cheapest(*a);
	target = cheapest->target_node;
	DEBUG_PRINT("cheapest_node: %d\n", cheapest->nb);
	DEBUG_PRINT("cheapest_cost: %d\n", cheapest->cost);

	if (!cheapest || !target)
		return ;
	if (cheapest->above_median && target->above_median)
		rev_rotate_both(cheapest, target, a, b);
	else if (cheapest->above_median && target->above_median)
		rotate_both(cheapest, target, a, b);
	else
	{
		move_up(cheapest, a, 'a');
		move_up(target, b, 'b');
	}
	pb(a, b);
}

void	rotate_both(t_stack *cheapest, t_stack *target, t_stack **a,
		t_stack **b)
{
	int	move_a;
	int	move_b;

	move_a = cheapest->index;
	move_b = target->index;
	while (move_a && move_b)
	{
		rr(a, b);
		move_a--;
		move_b--;
	}
	while (move_a)
	{
		ra(a);
		move_a--;
	}
	while (move_b)
	{
		rb(b);
		move_b--;
	}
}

void	rev_rotate_both(t_stack *cheapest, t_stack *target, t_stack **a,
		t_stack **b)
{
	int	move_a;
	int	move_b;

	move_a = cheapest->size - cheapest->index;
	move_b = target->size - target->index;
	while (move_a && move_b)
	{
		rrr(a, b);
		move_a--;
		move_b--;
	}
	while (move_a)
	{
		rra(a);
		move_a--;
	}
	while (move_b)
	{
		rrb(b);
		move_b--;
	}
}

void	move_up(t_stack *node, t_stack **stack, char c)
{
	int	move;

	move = !node->above_median ? node->index : (node->size - node->index);
	while (move)
	{
		if (!node->above_median)
		{
			if (c == 'a')
				ra(stack);
			else
				rb(stack);
			move--;
		}
		else
		{
			if (c == 'a')
				rra(stack);
			else
				rrb(stack);
			move--;
		}
	}
}
