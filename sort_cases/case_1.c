/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:11:21 by apple             #+#    #+#             */
/*   Updated: 2025/03/19 12:12:01 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void case_1(t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;

    first = *stack_a;
    second = first->next;
    third = second->next;
    if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
        return;
    if (first->data > second->data && second->data < third->data && first->data < third->data)
        swap_a(stack_a);
    else if (first->data > second->data && second->data > third->data)
    {
        swap_a(stack_a);
        reverse_rotate_a(stack_a);
    }
    else if (first->data > second->data && first->data > third->data)
        rotate_a(stack_a);
    else if (second->data > first->data && second->data > third->data && third->data > first->data)
    {
        swap_a(stack_a);
        rotate_a(stack_a);
    }
    else if (second->data > first->data && second->data > third->data && third->data < first->data)
        reverse_rotate_a(stack_a);
}


// void case_1_stack_b(t_size *s, int *stack_b)
// {
//     if (stack_b[0] < stack_b[1] && stack_b[2] < stack_b[1] && stack_b[2] < stack_b[0])
//         swap_b(stack_b);
//     else if (stack_b[0] < stack_b[1] && stack_b[1] < stack_b[2])
//     {
//         swap_b(stack_b);
//         reverse_rotate_b(s, stack_b);
//     }
//     else if (stack_b[1] > stack_b[0] && stack_b[1] > stack_b[2])
//         rotate_b(s, stack_b);
//     else if (stack_b[1] < stack_b[0] && stack_b[1] < stack_b[2] && stack_b[2] < stack_b[0])
//     {
//         swap_b(stack_b);
//         rotate_b(s, stack_b);
//     }
//     else if (stack_b[1] < stack_b[0] && stack_b[1] < stack_b[2] && stack_b[2] > stack_b[0])
//         reverse_rotate_b(s, stack_b);
// }