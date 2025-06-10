/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:28:57 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/10 16:24:25 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*max_node;
	t_stack	*min_node;

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

/*
On va jusau a : i<stack_size-5
		-3 pour les tris dernier de 3
		-2 pour les 2 deja push
*/
void	sort_turk(t_stack **a, t_stack **b, int stack_size)
{
	int i;
	t_stack *cheapest_node;

	i = 0;

	while (i < (stack_size - 5))
	{
		DEBUG_PRINT(" --------- A after ------- \n");
		show_nodes(*a);

		DEBUG_PRINT(" --------- B after ------- \n");
		show_nodes(*b);

		set_target(a, b);
		update_cost(a, b);
		cheapest_node = get_cheapest(*a);

		DEBUG_PRINT("after\n");
		DEBUG_PRINT("cheapest_node: %d\n", cheapest_node->nb);

		pb(a, b);

		i++;
	}
}