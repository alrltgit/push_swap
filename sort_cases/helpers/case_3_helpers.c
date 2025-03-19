/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:56:15 by apple             #+#    #+#             */
/*   Updated: 2025/03/19 17:48:55 by apple            ###   ########.fr       */
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

int find_count_to_zero_1(int hold_first_idx)
{
    int count_to_zero_1;

    count_to_zero_1 = 0;
    while (count_to_zero_1 < hold_first_idx)
        count_to_zero_1++;
    return (count_to_zero_1);
}

int find_count_to_zero_2(int hold_second_idx)
{
    int count_to_zero_2;

    count_to_zero_2 = 0;
    while (count_to_zero_2 < hold_second_idx)
        count_to_zero_2++;
    return (count_to_zero_2);
}

int find_count_to_zero(int hold_first_idx, int hold_second_idx, int middle_of_list)
{
    int count_to_zero;
    
    count_to_zero = 0;
    if (hold_first_idx < middle_of_list)
    {
        while (count_to_zero < hold_first_idx)
            count_to_zero++;
    }
    else if (hold_second_idx < middle_of_list)
    {
        while (count_to_zero < hold_second_idx)
            count_to_zero++;
    }
    return (count_to_zero);
}

int find_count_to_max_1(t_stack **stack_a, int hold_first_idx)
{
    int count_to_max_1;
    int temp;
    
    count_to_max_1 = 0;
    temp = hold_first_idx;
    while (temp < (int)count_stack_size(stack_a))
    {
        temp++;
        count_to_max_1++;
    }
    return (count_to_max_1);
}

int find_count_to_max_2(t_stack **stack_a, int hold_second_idx)
{
    int temp;
    int count_to_max_2;
    
    count_to_max_2 = 0;
    temp = hold_second_idx;
    while (temp < (int)count_stack_size(stack_a))
    {
        temp++;
        count_to_max_2++;
    }
    return (count_to_max_2);
}

int find_count_to_max(t_stack **stack_a, int hold_first_idx, int hold_second_idx, int middle_of_list)
{
    int count_to_max;
    int temp;

    count_to_max = 0;
    if (hold_first_idx > middle_of_list)
    {
        temp = hold_first_idx;
        while (temp < (int)count_stack_size(stack_a))
        {
            temp++;
            count_to_max++;
        }
    }
    else if (hold_second_idx > middle_of_list)
    {
        temp = hold_second_idx;
        while (temp < (int)count_stack_size(stack_a))
        {
            temp++;
            count_to_max++;
        }
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

void reverse_rotate_idx(t_stack **stack_a, int idx)
{
    int i;

    i = idx;
    while (i < (int)count_stack_size(stack_a))
    {
        reverse_rotate_a(stack_a);
        i++;
    }

}