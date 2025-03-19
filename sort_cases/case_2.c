/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:13:22 by apple             #+#    #+#             */
/*   Updated: 2025/03/19 12:26:29 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void find_min(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;
    t_stack *min_node;
    int find_idx;
    int i;

    temp = *stack_a;
    min_node = *stack_a;
    find_idx = 0;
    i = 0;
    if (!stack_a || !*stack_b)
        return ;
    while (temp)
    {
        if (temp->data < min_node->data)
        {
            min_node = temp;
            find_idx = i;
        }
        temp = temp->next;
        i++;
    }
    if (find_idx == 1)
        swap_a(stack_a);
    else if (find_idx == 2)
    {
        rotate_a(stack_a);
        rotate_a(stack_a);
    }
    else if (find_idx == 3 && count_stack_size(stack_a) == 5)
    {
        reverse_rotate_a(stack_a);
        reverse_rotate_a(stack_a);
    }
    else if (find_idx == 3 && count_stack_size(stack_a) == 4)
        reverse_rotate_a(stack_a);
    else if (find_idx == 4 && count_stack_size(stack_a) == 5)
        reverse_rotate_a(stack_a);
    push_b(stack_a, stack_b);
}
void case_2(t_stack **stack_a, t_stack **stack_b)
{
    find_min(stack_a, stack_b);
    ft_printf("stack_size: %d\n", count_stack_size(stack_a));
    if (count_stack_size(stack_a) == 4)
        find_min(stack_a, stack_b);
    case_1(stack_a);
    push_a(stack_a, stack_b);
    if (count_stack_size(stack_a) == 4 && *stack_b)
        push_a(stack_a, stack_b);
}

// void case_2_stack_b(t_size *s, int *stack_b)
// {
//     int i;

//     i = 0;
//     while (stack_b[0] < stack_b[1] && i <= s->b_size)
//     {
//         // ft_printf("stack_b[0]: %d\n", stack_b[0]);
//         // ft_printf("stack_a[1]: %d\n", stack_b[1]);
//         swap_b(stack_b);
//         rotate_b(s, stack_b);
//         i++;
//     }
//     i = s->b_size - 1;
//     while (stack_b[i] > stack_b[0])
//     {
//         reverse_rotate_b(s, stack_b);
//     }
// }