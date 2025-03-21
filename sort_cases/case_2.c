/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:13:22 by apple             #+#    #+#             */
/*   Updated: 2025/03/21 12:56:33 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void find_min(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;
    t_stack *min_node;
    int find_idx;
    int i;

    temp = *stack_a;
    min_node = *stack_a;
    find_idx = 0;
    i = 0;
    if (!stack_a)
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
    push_b(s, stack_a, stack_b);
}

void case_2(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    find_min(s, stack_a, stack_b);
    if (count_stack_size(stack_a) == 4)
        find_min(s, stack_a, stack_b);
    case_1(stack_a);
    push_a(s, stack_a, stack_b);
    if (count_stack_size(stack_a) == 4 && *stack_b)
        push_a(s, stack_a, stack_b);
}

void case_2_stack_b(t_stack **stack_b)
{
    t_stack *current;

    if (!stack_b || !(*stack_b) || !(*stack_b)->next)
        return ;
    current = *stack_b;
    while (current && current->data < current->next->data)
    {
        // ft_printf("current->data: %d ", current->data);
        swap_b(stack_b);
        rotate_b(stack_b);
        current = current->next;
    }
    current = *stack_b;
    while (current->next)
        current = current->next;
    ft_printf("last current->data: %d \n", current->data);
    while (current)
    {
        ft_printf("current->data: %d \n", current->data);
        if (current->data > current->prev->data)
        {
            reverse_rotate_b(stack_b);
        }
        current = current->prev;
    }
}