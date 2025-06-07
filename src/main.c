/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:54:06 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/06/07 17:14:03 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack **a;
    t_stack **b;
        
    a = NULL;
    b = NULL;

    DEBUG_PRINT(" --------- Starts ------- \n");
    ft_printf("pas debug\n");
	if ((ac == 1) || (ac == 2 && !av[1][0]))
        return(1);
    if(ac == 2 && av[1])
        av = ft_split(av[1], ' ');
    init_stack(a,av);   
    show_nodes(*a);

    //verifier si liste deja triee
    //verifier si moins de 3 arg
    //definir les target node pour chaque node
    //get the cost of each node to get to the target node
    //find the cheapest node
        
    return(0);
}