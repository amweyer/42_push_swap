/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayaweyer <amayaweyer@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:55:20 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/05/31 13:21:09 by amayaweyer       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void init_stack(t_stack **a, char **av)
{
    int i;

    i = 0;
    while(av[i])
    {
        if(ft_check_errors(a, av[i]))
        {
            free_errors(a);
            return;
        }
        add_node(a, av);
        i++;
    }
}