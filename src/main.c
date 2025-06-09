/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:54:06 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/06/09 15:17:21 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	int start;

	a = NULL;
	b = NULL;
	start = 1;

	DEBUG_PRINT(" --------- START ------- \n");
	if ((ac == 1) || (ac == 2 && !av[1][0]))
	{
		DEBUG_PRINT(" ENTRE ERREUR \n");
		return (1);
	}
	if (ac == 2 && av[1])
	{
		av = ft_split(av[1], ' ');
		start = 0;
	}
	init_stack(&a, av, start);

	DEBUG_PRINT(" --------- A before ------- \n");
	show_nodes(a);
	DEBUG_PRINT(" --------------------- \n");

    DEBUG_PRINT(" --------- B before ------- \n");
    show_nodes(b);
	DEBUG_PRINT(" --------------------- \n");

	if (is_sorted(a))
	{
		DEBUG_PRINT(" --------- Sorted ------- \n");
		return (1);
	}

	if (get_stack_size(a) > 3)
    {
        pb(&a,&b);
        pb(&a,&b);
		
		sort_turk(&a,&b);
		
    }

    sort_three(&a);

	// DEBUG_PRINT("max nb node : %d\n" , get_max_node(a)->nb);
	// DEBUG_PRINT("max nb node : %d\n" , get_min_node(a)->nb);
    

    
	DEBUG_PRINT(" --------- A after ------- \n");
	show_nodes(a);
	DEBUG_PRINT(" --------------------- \n");

    DEBUG_PRINT(" --------- B after ------- \n");
    show_nodes(b);
    DEBUG_PRINT(" --------------------- \n");


	DEBUG_PRINT(" --------- FINISH ------- \n");

	// definir les target node pour chaque node
	// get the cost of each node to get to the target node
	// find the cheapest node

	return (0);
}