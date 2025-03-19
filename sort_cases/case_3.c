/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:58:14 by apple             #+#    #+#             */
/*   Updated: 2025/03/19 17:58:18 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void find_place_in_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current;
    t_stack *next_node;
    size_t len_b;

    len_b = count_stack_size(stack_b);    
    if (len_b == 0)
    {
        push_b(stack_a, stack_b);
        return ;
    }
    current = *stack_b;
    if ((*stack_a)->data > current->data)
    {
        push_b(stack_a, stack_b);
        return ;
    }
    else if (current->data > (*stack_a)->data)
    {
        push_b(stack_a, stack_b);
        if (len_b == 3)
            case_1_stack_b(stack_b);
        // else
        //     case_2_stack_b(stack_b);
        return ;
    }
    while (current && current->next)
    {
        next_node = current->next;
        if ((*stack_a)->data >= current->data && (*stack_a)->data <= next_node->data)
        {
            while (current != *stack_b)
            {
                rotate_b(stack_b);
                current = *stack_b;
            }
            push_b(stack_a, stack_b);
            return ;
        }
        current = current->next;
    }
    if ((*stack_a)->data < current->data)
    {
        push_b(stack_a, stack_b);
        rotate_b(stack_b);
        return ;
    }
}

void case_3(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp_a;
    int hold_first;
    int hold_second;
    int middle_of_list;
    int hold_first_idx;
    int hold_second_idx;
    int count_to_zero;
    int count_to_max;
    int chunk_size;
    int chunk_min;
    int chunk_max;
    int chunk;
    int i;

    chunk_size = count_stack_size(stack_a) / 5;
    middle_of_list =count_stack_size(stack_a) / 2;
    chunk = 0;
    while (chunk <= 5)
    {
        chunk_min = chunk * chunk_size;
        chunk_max = chunk_min + chunk_size - 1;

        int j = chunk_min;
        while (j < chunk_max)
        {
            
            hold_first = find_hold_first(stack_a, chunk_min, chunk_max);
            if (!hold_first)
                break ;
            hold_second = find_hold_second(stack_a, chunk_min, chunk_max);
            if (!hold_second)
                break ;
            i = 0;
            temp_a = *stack_a;
            while (temp_a)
            {
                if (temp_a->data == hold_first)
                {
                    hold_first_idx = i;
                }
                else if (temp_a->data == hold_second)
                {
                    hold_second_idx = i;
                }
                i++;
                temp_a = temp_a->next;
            }
            count_to_max = find_count_to_max(stack_a, hold_first_idx, hold_second_idx, middle_of_list);
            count_to_zero = find_count_to_zero(hold_first_idx, hold_second_idx, middle_of_list);
            
            if (hold_first_idx > middle_of_list && hold_second_idx > middle_of_list)
                nums_in_second_part(stack_a, hold_first_idx, hold_second_idx);
            else if (hold_first_idx == hold_second_idx && hold_first_idx > middle_of_list && hold_second_idx > middle_of_list)
                reverse_rotate_idx(stack_a, hold_second_idx);
            else if (hold_first_idx < middle_of_list && hold_second_idx < middle_of_list)
                nums_in_first_part(stack_a, hold_first_idx, hold_second_idx);
            else if (hold_first_idx == hold_second_idx && hold_first_idx < middle_of_list && hold_second_idx < middle_of_list)
                rotate_idx(stack_a, hold_first_idx);
            else if (count_to_zero < count_to_max && hold_first_idx < middle_of_list)
                rotate_idx(stack_a, hold_first_idx);
            else if (count_to_zero < count_to_max && hold_second_idx < middle_of_list)
                rotate_idx(stack_a, hold_second_idx);
            else if (count_to_zero > count_to_max && hold_first_idx > middle_of_list)
                reverse_rotate_idx(stack_a, hold_first_idx);
            else if (count_to_zero > count_to_max && hold_second_idx > middle_of_list)
                reverse_rotate_idx(stack_a, hold_second_idx);
            else if (hold_first_idx > middle_of_list && hold_second_idx > middle_of_list)
                reverse_rotate_idx(stack_a, hold_second_idx);
            find_place_in_b(stack_a, stack_b);
            j++;
        }
        chunk++;
    }
}

// 44 77 28 36 56 74 78 60 30 47 35 46 2 59 8 82 24 51 57 94 18 33 4 22 73 81 90 25 31 98 48 54 72 15 9 23 1 68 92 14 63 40 86 10 61 17 12 88 50 84 45 37 5 34 75 100 52 26 70 91 89 7 96 20 85 95 49 71 6 13 79 19 99 53 69 38 27 11 41 67 21 83 39 62 87 43 32 29 76 65 93 55 58 16 3 80 64 97 42 66

//       "args": [
//     "44", "77", "28", "36", "56", "74", "78", "60", "30", "47", "35", "46", "2", "59", "8", "82", "24", "51", "57", "94", "18", "33", "4", "22", "73", "81", "90", "25", "31", "98", "48", "54", "72", "15", "9", "23", "1", "68", "92", "14", "63", "40", "86", "10", "61", "17", "12", "88", "50", "84", "45", "37", "5", "34", "75", "100", "52", "26","70", "91", "89", "7", "96", "20", "85", "95", "49", "71", "6", "13", "79", "19", "99", "53", "69", "38", "27", "11", "41", "67", "21", "83", "39", "62", "87", "43", "32", "29", "76", "65", "93", "55", "58", "16", "3", "80", "64", "97", "42", "66" 
    //   ],