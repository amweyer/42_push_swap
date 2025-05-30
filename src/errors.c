/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayaweyer <amayaweyer@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:59:14 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/05/30 11:40:26 by amayaweyer       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_synthax(char *arg)
{
    int i;

    i = 0;
    if(arg[i]== '+' || arg[i] == '-')
        i++;
    while(arg[i])
    {
        if(!ft_isdigit(arg[i]))
            return(1);
        i++;
    }
    return(0);
}

int	ft_check_duplicates(t_stack **a, int n)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->nb == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	ft_check_errors(char *arg)
{
	if(ft_check_duplicates(arg))
	    return(1);
	if(ft_check_synthax(arg))
	    return(1);
}