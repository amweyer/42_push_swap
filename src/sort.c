/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:28:57 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/08 14:05:15 by amweyer          ###   ########.fr       */
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