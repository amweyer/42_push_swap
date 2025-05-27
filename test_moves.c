/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayaweyer <amayaweyer@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:53:53 by amayaweyer        #+#    #+#             */
/*   Updated: 2025/05/27 11:53:58 by amayaweyer       ###   ########.fr       */
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
        printf("%d ", head->nb);
        head = head->next;
    }
    printf("\n");
}

void test_ps_swap(t_stack **head)
{
    printf("------------------ PS_SWAP ------------------  \n");
    printf("Before swap: ");
    print_stack(*head);

    swap(head);

    printf("After swap:  ");
    print_stack(*head);
    printf("------------------  ------------------  \n");

}


void test_ps_push(t_stack **a, t_stack **b)
{
        printf("------------------ PS_PUSH ------------------  \n");
        printf("Before pa: \n");
        print_stack(*a);
        print_stack(*b);

        pa(a,b);
        printf("After pa: \n");
        print_stack(*a);
        print_stack(*b);

        pb(a,b);
        printf("After pb: \n");
        print_stack(*a);
        print_stack(*b);

        printf("------------------  ------------------  \n");

}

void test_ps_rotate(t_stack **a, t_stack **b)
{
        printf("------------------ PS_ROTATE ------------------  \n");
        printf("Before ra: \n");
        print_stack(*a);

        ra(a);
        printf("After ra: \n");
        print_stack(*a);

        printf("Before rb: \n");
        print_stack(*b);

        ra(b);
        printf("After rb: \n");
        print_stack(*b);

        printf("Before rr: \n");
        print_stack(*a);
        print_stack(*b);

        rr(a,b);
        printf("After rr: \n");
        print_stack(*a);
        print_stack(*b);

        printf("------------------  ------------------  \n");
}

void test_ps_revrse_rotate(t_stack **a, t_stack **b)
{
        printf("------------------ PS_ROTATE ------------------  \n");
        printf("Before ra: \n");
        print_stack(*a);

        rra(a);
        printf("After ra: \n");
        print_stack(*a);

        printf("Before rrb: \n");
        print_stack(*b);

        rrb(b);
        printf("After rb: \n");
        print_stack(*b);

        printf("Before rr: \n");
        print_stack(*a);
        print_stack(*b);

        rrr(a,b);
        printf("After rr: \n");
        print_stack(*a);
        print_stack(*b);

        printf("------------------  ------------------  \n");
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
    // test_ps_revrse_rotate(&stack_a,&stack_b);

   

    // free memory
    free(c);
    free(b);
    free(a);

    return 0;
}
