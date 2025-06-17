/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:35:03 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/17 11:42:09 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_closest_bigger(t_stack *node, t_stack **stack)
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
		diff = current_node->nb - node->nb;
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
		node->target_node = get_min_node(*stack);
}

void	set_target_back(t_stack **a, t_stack **b)
{
	t_stack	*current_node;

	current_node = *a;
	while (current_node)
	{
		get_closest_bigger(current_node, b);
		current_node = current_node->next;
	}
}

