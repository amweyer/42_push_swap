/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:27:53 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/23 15:26:58 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!head || !*head || !(*head)->next)
		return ;
	current = *head;
	tmp = current;
	*head = current->next;
	(*head)->prev = NULL;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->prev = current;
	tmp->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
