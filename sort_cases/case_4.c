/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:35:05 by apple             #+#    #+#             */
/*   Updated: 2025/03/21 19:37:15 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// t_stack *next_num(t_stack **stack)
// {
//     t_stack *temp;

//     temp = *stack;
//     while (temp->next)
//         temp = temp->next;
//     return (temp);
// }

// void find_location_in_b(t_size *s, t_stack **stack_a, t_stack **stack_b)
// {
//     t_stack *current_a;
//     t_stack *current_b;

//     if (s->b_size == 0)
//     {
//         push_b(s, stack_a, stack_b);
//         return ;
//     }
//     current_a = *stack_a;
//     current_b = *stack_b;
//     if (current_a->data > current_b->data)
//     {
//         push_b(s, stack_a, stack_b);
//         return ;
//     }
//     else if (current_a->data < next_num(stack_b)->data)
//     {
//         push_b(s, stack_a, stack_b);
//         rotate_b(stack_b);
//     }
//     else if (current_a->data < current_b->data)
//     {
//         current_b = *stack_b;
//         while (current_b && !(current_a->data < current_b->data && current_a->data > current_b->next->data))
//         {
//             rotate_b(stack_b);
//             current_b = *stack_b;
//         }
//         push_b(s, stack_a, stack_b);
//         swap_b(stack_b);
//         if (stack_b_is_sorted(stack_b))
//             return ;
//         else
//         {
//             current_b = *stack_b;
//             while (current_b->next)
//                 current_b = current_b->next;
//             while (current_b && current_b->data < current_b->prev->data)
//             {
//                 reverse_rotate_b(stack_b);
//                 current_b = next_num(stack_b);
//             }
//             if (current_b->data > current_b->prev->data)
//                 reverse_rotate_b(stack_b);
//             return ;
//         }
//     }
// }

int find_lowest_first(t_stack **stack_a)
{
    t_stack *temp;
    int hold_first;

    temp = *stack_a;
    hold_first = temp->data;
    while (temp)
    {
        if (temp->data < hold_first)
        {
            hold_first = temp->data;
        }
        temp = temp->next;
    }
    return (hold_first);
}

int find_lowest_second(t_stack **stack_a)
{
    t_stack *temp;
    int hold_second;
    int len;
    int i;

    temp = *stack_a;
    len = 0;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    temp = *stack_a;
    i = 0;
    while (i < len - 1)
    {
        temp = temp->next;
        i++;
    }
    hold_second = temp->data;
    while (temp)
    {
        if (temp->data < hold_second)
        {
            hold_second = temp->data;
        }
        temp = temp->prev;
    }
    return(hold_second);
}

int find_lowest_to_zero(int hold_first_idx)
{
    int count_to_zero;
    
    count_to_zero = 0;
    while (count_to_zero < hold_first_idx)
        count_to_zero++;
    return (count_to_zero);
}

int find_lowest_to_max(t_size *s, int hold_second_idx)
{
    int count_to_max;
    int temp;

    count_to_max = 0;
    temp = hold_second_idx;
    while (temp < s->a_size)
    {
        temp++;
        count_to_max++;
    }
    return (count_to_max);
}

void case_4(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    int chunk;
    int num_chunks;
    int chunk_size;
    t_stack *temp;
    int lowest_first_idx = 0;
    int lowest_second_idx = 0;
    int lowest_to_max;
    int lowest_to_zero;
    
    num_chunks = 0;
    if (s->a_size <= 20)
        num_chunks = 2;
    else if (s->a_size <= 50)
        num_chunks = 4;
    else if (s->a_size <= 99)
        num_chunks = 5;

    (void)stack_b;
    chunk_size = s->a_size / num_chunks;
    chunk = 0;
    while (chunk < chunk_size)
    {
        int j = 0;
        while (j < s->a_size)
        {
             // int min = chunk * chunk_size;
            // int max = chunk_size + min - 1;
            int lowest_first = find_lowest_first(stack_a);
            int lowest_second = find_lowest_second(stack_a);
            if (!lowest_first || !lowest_second)
            {
                ft_printf("Lowest number is not found.\n");
                return ;
            }
            ft_printf("lowest_first: %d\n lowest_second: %d\n", lowest_first, lowest_second);
            temp = *stack_a;
            int i = 0;
            while (temp)
            {
                if (temp->data == lowest_first)
                    lowest_first_idx = i;
                if (temp->data == lowest_second)
                    lowest_second_idx = i;
                temp = temp->next;
                i++;
            }
            ft_printf("lowest_first_idx: %d\n lowest_second_idx: %d\n", lowest_first_idx, lowest_second_idx);
            lowest_to_zero = find_lowest_to_zero(lowest_first_idx);
            lowest_to_max = find_lowest_to_max(s, lowest_second_idx);
            ft_printf("lowest_to_zero: %d\n lowest_to_max: %d\n", lowest_to_zero, lowest_to_max);
            if (lowest_to_zero > lowest_to_max)
                reverse_rotate_idx(s, stack_a, lowest_second_idx);
            else
                rotate_idx(stack_a, lowest_first_idx);
            j++;
        }
        push_b(s, stack_a, stack_b);
        chunk++;
    }
}