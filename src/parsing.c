/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:55:20 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/06/07 18:15:56 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **a, char **av, int start)
{
	int i;

	i = start;
	while (av[i] != NULL)
	{
		DEBUG_PRINT("Entre init_stack avec : %s\n", av[i]);
		if (check_errors(a, av[i]))
		{
			free_errors(a);
			return ;
		}
		add_node(a, ft_atol(av[i]));
		DEBUG_PRINT("node added");
		i++;
	}
}