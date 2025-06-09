/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:38:07 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/09 15:14:48 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_closest(t_stack *node, t_stack **stack)
{
    bool found;
    t_stack *current_node;

    current_node = *stack;
    found = 0;

    while(current_node->next && !found)
    {
        if((node->nb > current_node->nb) && (node->nb < current_node->next->nb))
        {
            node->target_node = current_node;
            found = 1;
        }
        current_node = current_node->next;
    }
    if(!found)
        node->target_node =  get_max_node(*stack);

}

void	set_target(t_stack **a, t_stack **b)
{
	t_stack	*current_node;

	if (!a || !*a || !b || !*b)
		return ;
	current_node = *a;
	while (current_node)
	{
        get_closest(current_node, b);
        DEBUG_PRINT("node:%d target :%d \n", current_node->nb, current_node->target_node->nb );
        current_node = current_node->next;
    }
}

// void update_index(t_stack stack)
// {

// }

// void update_cost(t_stack stack)
// {

// }

// t_stack get_cheapest(t_stack stack)
// {

// }
