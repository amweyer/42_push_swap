/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayaweyer <amayaweyer@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:55:20 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/05/28 15:06:21 by amayaweyer       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//ft_atol 

void stack_creator(t_stack **a, char **av)
{
    int i;

    i = 0;
    while(av[i])
    {
        if(ft_check_errors(av[i]))
        {
            //free(stask)
            return(1);
        }
    }
}