/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:12:05 by amweyer           #+#    #+#             */
/*   Updated: 2025/06/10 15:59:44 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
#include <stdbool.h> 

#include <stdio.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

/* debug macro */
# define DEBUG 1

# if DEBUG == 1
#  define DEBUG_PRINT(fmt, ...) ft_printf("[DEBUG] %s:%d: " fmt "\n", __FILE__,__LINE__, ##__VA_ARGS__)
# else
#  define DEBUG_PRINT(fmt, ...) \
	do                        \
	{                         \
	} while (0)
# endif

typedef struct s_stack
{
	int				nb;
	int				index;
	int 			cost;
	int				size;
	bool 			above_median;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				swap(t_stack **head);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

void				push(t_stack **head_src, t_stack **head_dst);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

void				rotate(t_stack **head);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				rrotate(t_stack **head);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

/* parsing.c */
void				init_stack(t_stack **a, char **av, int start);
void				add_node(t_stack **a, int n);
void				show_nodes(t_stack *a);
int					is_sorted(t_stack *stack);

/* errors.c */
int					check_error_synthax(char *arg);
int					check_is_int(char *arg);
int					check_error_duplicates(t_stack **a, char *arg);
int					check_errors(t_stack **a, char *arg);
void				free_stack(t_stack **stack);
void				free_errors(t_stack **a);

/* utils.c */
long				ft_atol(char *arg);
int 				ft_max(int a, int b);
int 				ft_min(int a, int b);

/* stack_utils.c */
int					get_stack_size(t_stack *stack);
void				update_stack_size(t_stack **stack);
t_stack				*get_max_node(t_stack *stack);
t_stack				*get_min_node(t_stack *stack);


/* sort.c */
void	sort_three(t_stack **stack);
void sort_turk(t_stack **a, t_stack **b, int stack_size);

/* sort_utils.c */
void	get_closest(t_stack *node, t_stack **stack);
void	set_target(t_stack **a, t_stack **b);
void	update_index(t_stack **stack);
int 	get_median(t_stack *stack);
void update_median(t_stack **stack);
void set_cost(t_stack **node);
void update_cost(t_stack **a, t_stack **b);
t_stack *get_cheapest(t_stack *stack);






#endif