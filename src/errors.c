/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:59:14 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/06/08 12:56:37 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error_synthax(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_is_int(char *arg)
{
	long	n;

	n = ft_atol(arg);
	if (n < INT_MIN || n > INT_MAX)
		return (1);
	return (0);
}

int	check_error_duplicates(t_stack **a, char *arg)
{
	long	n;
	t_stack	*tmp;

	if (!arg)
		return (1);
	if (!a || !*a)
		return (0);
	n = atol(arg);
	tmp = *a;
	while (tmp)
	{
		if (tmp->nb == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_errors(t_stack **a, char *arg)
{
	// DEBUG_PRINT("Enter : check_errors");
	if (!arg)
	{
		DEBUG_PRINT("Errror from: 0");
		return (1);
	}
	if (check_error_synthax(arg))
	{
		DEBUG_PRINT("Errror from: 1");
		return (1);
	}
	if (check_is_int(arg))
	{
		DEBUG_PRINT("Errror from: 2");
		return (1);
	}
	if (check_error_duplicates(a, arg))
	{
		DEBUG_PRINT("Errror from: 3");
		return (1);
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->index = 0;
		current->nb = 0;
		current->prev = NULL;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	exit(1);
}