/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:54:40 by amweyer           #+#    #+#             */
/*   Updated: 2025/05/23 15:26:53 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **head_src, t_stack **head_dst)
{
	t_stack	*tmp;

	if (!head_src || !*head_src)
		return ;
	tmp = *head_src;
	*head_src = tmp->next;
	if (*head_src)
		(*head_src)->prev = NULL;
	tmp->next = *head_dst;
	tmp->prev = NULL;
	*head_dst = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
