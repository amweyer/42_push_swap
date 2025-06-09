/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:28:57 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/09 15:07:54 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack *max_node;
	t_stack *min_node;
	if (!stack)
		return ;
	max_node = get_max_node(*stack);
	min_node = get_min_node(*stack);
	if (max_node == *stack)
		ra(stack);
	else if (max_node == (*stack)->next)
		rra(stack);
	if (min_node == (*stack)->next)
		sa(stack);
}

void sort_turk(t_stack **a, t_stack **b)
{
	set_target(a,b);
}