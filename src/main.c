/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayaweyer <amayaweyer@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:54:06 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/05/30 11:37:45 by amayaweyer       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    stack_t **a;
    stack_t **b;
        
    a = NULL;
    b = NULL;

	if ((ac == 1) || (ac == 2 && !av[1][0]))
        return(1);
    if(ac == 2 && av[1])
        av = ft_split(av[1], ' ');
    init_stack(a,av);     
    // ft_printf("test");
        
    return(0);
}

