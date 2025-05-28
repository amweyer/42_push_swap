/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayaweyer <amayaweyer@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:59:14 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/05/28 15:10:02 by amayaweyer       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_synthax(char *arg)
{
    
}

int ft_check_duplicates(t_stack **a, int nb)
{
    
}

int ft_check_errors(char *arg)
{
    if(ft_check_duplicates(arg))
        return(1);
    if(ft_check_synthax(arg))
        return(1);
    
    
}