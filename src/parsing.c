/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:55:20 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/06/17 12:16:01 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_stack **a, int n)
{
	t_stack	*new_block;
	t_stack	*tmp;

	new_block = malloc(sizeof(t_stack));
	if (!a || !new_block)
		return ;
	new_block->nb = n;
	new_block->index = 0;
	new_block->next = NULL;
	new_block->prev = NULL;
	if (!*a)
		*a = new_block;
	else
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_block;
		new_block->prev = tmp;
	}
}
void	show_nodes(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		//ft_printf("%d\n", stack->nb);
		stack = stack->next;
	}
	//ft_printf("\n");

}

void	init_stack(t_stack **a, char **av, int start)
{
	int	i;
	int error;

	error = 0;
	i = start;
	while (av[i] != NULL)
	{
		// DEBUG_PRINT("Entre init_stack avec : %s\n", av[i]);
		if (check_errors(a, av[i]))
		{
			free_errors(a);
			return ;
		}
		add_node(a, ft_atol(av[i], &error));
		// DEBUG_PRINT("node added");
		i++;
	}
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}