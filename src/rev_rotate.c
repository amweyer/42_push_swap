/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:43:55 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/23 15:27:03 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!head || !*head || !(*head)->next)
		return ;
	current = *head;
	while (current->next)
		current = current->next;
	tmp = current;
	current->prev->next = NULL;
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
}

void	rra(t_stack **a)
{
	rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}
