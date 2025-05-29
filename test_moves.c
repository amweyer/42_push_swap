/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:53:53 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/05/29 13:32:09 by amweyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


t_stack *new_node(int nb) {
    t_stack *node = malloc(sizeof(t_stack));
    if (!node) return NULL;
    node->nb = nb;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void print_stack(t_stack *head) {
    while (head) {
        ft_printf("%d ", head->nb);
        head = head->next;
    }
    ft_printf("\n");
}

void test_ps_swap(t_stack **head)
{
    ft_printf("------------------ PS_SWAP ------------------  \n");
    ft_printf("Before swap: ");
    print_stack(*head);

    swap(head);

    ft_printf("After swap:  ");
    print_stack(*head);
    ft_printf("------------------  ------------------  \n");

}


void test_ps_push(t_stack **a, t_stack **b)
{
        ft_printf("------------------ PS_PUSH ------------------  \n");
        ft_printf("Before pa: \n");
        print_stack(*a);
        print_stack(*b);

        pa(a,b);
        ft_printf("After pa: \n");
        print_stack(*a);
        print_stack(*b);

        pb(a,b);
        ft_printf("After pb: \n");
        print_stack(*a);
        print_stack(*b);

        ft_printf("------------------  ------------------  \n");

}

void test_ps_rotate(t_stack **a, t_stack **b)
{
        ft_printf("------------------ PS_ROTATE ------------------  \n");
        ft_printf("Before ra: \n");
        print_stack(*a);

        ra(a);
        ft_printf("After ra: \n");
        print_stack(*a);

        ft_printf("Before rb: \n");
        print_stack(*b);

        ra(b);
        ft_printf("After rb: \n");
        print_stack(*b);

        ft_printf("Before rr: \n");
        print_stack(*a);
        print_stack(*b);

        rr(a,b);
        ft_printf("After rr: \n");
        print_stack(*a);
        print_stack(*b);

        ft_printf("------------------  ------------------  \n");
}

void test_ps_revrse_rotate(t_stack **a, t_stack **b)
{
        ft_printf("------------------ PS_ROTATE ------------------  \n");
        ft_printf("Before ra: \n");
        print_stack(*a);

        rra(a);
        ft_printf("After ra: \n");
        print_stack(*a);

        ft_printf("Before rrb: \n");
        print_stack(*b);

        rrb(b);
        ft_printf("After rb: \n");
        print_stack(*b);

        ft_printf("Before rr: \n");
        print_stack(*a);
        print_stack(*b);

        rrr(a,b);
        ft_printf("After rr: \n");
        print_stack(*a);
        print_stack(*b);

        ft_printf("------------------  ------------------  \n");
}

int main(void) {
    t_stack *a, *b, *c, *d, *e, *f, *m, *n;

    a = new_node(1);
    b = new_node(2);
    c = new_node(3);
    m = new_node(4);

    d = new_node(14);
    e = new_node(15);
    f = new_node(16);
    n = new_node(17);


    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    c->next = m;
    m->prev = c;

    d->next= e;
    e->prev = d;
    e->next = f;
    f->prev = e;
    f->next = n;
    n->prev = f;

    t_stack *stack_a = a;
    t_stack *stack_b = d;

    //test 1 : swap
    //test_ps_swap(&stack_a);

    //test 2 : push
    //test_ps_push(&stack_a,&stack_b);

    //test 3 : rotate
    // test_ps_rotate(&stack_a,&stack_b);

    //test 4 : reverse rotate
    test_ps_revrse_rotate(&stack_a,&stack_b);

   

    // free memory
    free(c);
    free(b);
    free(a);

    return 0;
}
