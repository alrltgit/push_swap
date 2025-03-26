/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:56:15 by apple             #+#    #+#             */
/*   Updated: 2025/03/26 12:06:05 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int find_hold_first(t_stack **stack_a, int chunk_min, int chunk_max)
{
    t_stack *temp;
    int hold_first;

    temp = *stack_a;
    hold_first = 0;
    while (temp)
    {
        if (temp->data >= chunk_min && temp->data <= chunk_max)
        {
            hold_first = temp->data;
            return (hold_first);
        }
        temp = temp->next;
    }
    return (hold_first);
}

int find_hold_second(t_stack **stack_a, int chunk_min, int chunk_max)
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
    hold_second = 0;
    while (temp)
    {
        if (temp->data >= chunk_min && temp->data <= chunk_max)
        {
            hold_second = temp->data;
            return (hold_second);
        }
        temp = temp->prev;
    }
    return(hold_second);
}

// int find_count_to_zero(int hold_first_idx)
// {
//     int count_to_zero;
    
//     count_to_zero = 0;
//     while (count_to_zero < hold_first_idx)
//         count_to_zero++;
//     return (count_to_zero);
// }

int find_count_to_zero(t_stack **stack, int value)
{
    t_stack *temp;
    int idx;

    temp = *stack;
    idx = 0;
    while (temp)
    {
        if (temp->data == value)
            break ;
        temp = temp->next;
        idx++;
    }
    // ft_printf("temp->data: %d\n", temp->data);
    // ft_printf("idx: %d\n", idx);
    return (idx);
}

int find_count_to_max(t_size *s, int hold_second_idx)
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

void rotate_idx(t_stack **stack_a, int idx)
{
    int i;
    
    i = idx;
    while (i > 0)
    {
        rotate_a(stack_a);
        i--;
    }
}

void reverse_rotate_idx(t_size *s, t_stack **stack_a, int idx)
{
    int i;

    i = idx;
    while (i < s->a_size)
    {
        reverse_rotate_a(stack_a);
        i++;
    }
}