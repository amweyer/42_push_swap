/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:54:06 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/06/12 17:21:00 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	int start;
	int stack_size;

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

    DEBUG_PRINT(" --------- B before ------- \n");
    show_nodes(b);

	if (is_sorted(a))
	{
		DEBUG_PRINT(" --------- Sorted ------- \n");
		return (1);
	}

	stack_size = get_stack_size(a);

	if (stack_size > 3)
    {
        pb(&a,&b);
        pb(&a,&b);
		
		sort_turk(&a,&b,stack_size);
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
	
	//DEBUG_PRINT("stack_size: %d\n", stack_size);

	DEBUG_PRINT(" --------- FINISH ------- \n");

	// definir les target node pour chaque node
	// get the cost of each node to get to the target node
	// find the cheapest node

	return (0);
}

// void	print_stack(t_stack *head)
// {
// 	while (head)
// 	{
// 		printf("%d ", head->nb);
// 		head = head->next;
// 	}
// 	printf("\n");
// }
// int	main(void)
// {
// 	t_stack *a = malloc(sizeof(t_stack));
// 	t_stack *b = malloc(sizeof(t_stack));
// 	//t_stack *c = malloc(sizeof(t_stack));

// 	a->nb = 1;
// 	b->nb = 2;
// 	// c->nb = 3;

// 	a->prev = NULL;
// 	a->next = b;
// 	b->prev = a;
// 	b->next = NULL;
// 	// c->prev = b;
// 	// c->next = ;

// 	t_stack *head = a;

// 	printf("Avant rrotate:\n");
// 	print_stack(head);

// 	rrotate(&head);

// 	printf("Après rrotate:\n");
// 	print_stack(head);

// 	// Libération mémoire
// 	free(a);
// 	free(b);
// 	// free(c);

// 	return 0;
// }
