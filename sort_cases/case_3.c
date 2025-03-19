/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:58:14 by apple             #+#    #+#             */
/*   Updated: 2025/03/18 15:08:52 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void find_place_in_b(t_size *s, int *stack_a, int **stack_b)
{
    int i;
    
    i = 0;
    while (i <= s->b_size)
    {
        if (s->b_size == 0)
        {
            // ft_printf("s->b_size == 0\n");
            push_b(s, stack_a, stack_b);
            return ;
        }
        else if (stack_a[0] > (*stack_b)[0])
        {
            // ft_printf("stack_a[0] > stack_b[0]\n");
            push_b(s, stack_a, stack_b);
            return ;
        }
        else if ((*stack_b)[0] > stack_a[0])
        {
            // ft_printf("stack_b[0] > stack_a[0]\n");
            push_b(s, stack_a, stack_b);
            if (s->b_size == 3)
                case_1_stack_b(s, *stack_b);
            else
                case_2_stack_b(s, *stack_b);
            return ;
        }
        else if (stack_a[0] >= (*stack_b)[i] && stack_a[0] <= (*stack_b)[i + 1])
        {
            // ft_printf("stack_a[0] >= stack_b[i] && stack_a[0] <= stack_b[i + 1]\n");
            while (i > 0)
            {
                rotate_b(s, *stack_b);
                i--;
            }
            push_b(s, stack_a, stack_b);
            return ;
        }
        else if (stack_a[0] < (*stack_b)[s->b_size])
        {
            // ft_printf("stack_b[0] < stack_b[s->b_size]\n");
            push_b(s, stack_a, stack_b);
            rotate_b(s, *stack_b);
            return ;
        }
        i++;
    }
}

void case_3(t_size *s, int *stack_a, int **stack_b)
{
    int hold_first;
    int hold_second;
    int middle_of_list;
    int i;
    int hold_first_idx;
    int hold_second_idx;
    int count_to_zero;
    int count_to_max;
    int chunk_size;
    int chunk_min;
    int chunk_max;
    int chunk;

    chunk_size = s->a_size / 5;
    middle_of_list = s->a_size / 2;
    chunk = 0;
    while (chunk <= 5)
    {
        chunk_min = chunk * chunk_size;
        chunk_max = chunk_min + chunk_size - 1;

        int j = chunk_min;
        // while (j <= 19)
        while (j < chunk_max)
        {
            hold_first = find_hold_first(s, stack_a, chunk_min, chunk_max);
            if (!hold_first)
                break ;
            hold_second = find_hold_second(s, stack_a, chunk_min, chunk_max);
            if (!hold_second)
                break ;
            i = 0;
            while (i < s->a_size)
            {
                if (stack_a[i] == hold_first)
                {
                    hold_first_idx = i;
                    // ft_printf("hold_first_idx: %d\n", hold_first_idx);
                }
                else if (stack_a[i] == hold_second)
                {
                    hold_second_idx = i;
                    // ft_printf("hold_second_idx: %d\n", hold_second_idx);
                }
                i++;
            }
            count_to_max = find_count_to_max(s, hold_first_idx, hold_second_idx, middle_of_list);
            count_to_zero = find_count_to_zero(hold_first_idx, hold_second_idx, middle_of_list);
            
            if (hold_first_idx > middle_of_list && hold_second_idx > middle_of_list)
                nums_in_second_part(s, hold_first_idx, hold_second_idx, stack_a);
            else if (hold_first_idx == hold_second_idx && hold_first_idx > middle_of_list && hold_second_idx > middle_of_list)
                reverse_rotate_idx(s, stack_a, hold_second_idx);
            else if (hold_first_idx < middle_of_list && hold_second_idx < middle_of_list)
                nums_in_first_part(s, hold_first_idx, hold_second_idx, stack_a);
            else if (hold_first_idx == hold_second_idx && hold_first_idx < middle_of_list && hold_second_idx < middle_of_list)
                rotate_idx(s, stack_a, hold_first_idx);
            else if (count_to_zero < count_to_max && hold_first_idx < middle_of_list)
                rotate_idx(s, stack_a, hold_first_idx);
            else if (count_to_zero < count_to_max && hold_second_idx < middle_of_list)
                rotate_idx(s, stack_a, hold_second_idx);
            else if (count_to_zero > count_to_max && hold_first_idx > middle_of_list)
                reverse_rotate_idx(s, stack_a, hold_first_idx);
            else if (count_to_zero > count_to_max && hold_second_idx > middle_of_list)
                reverse_rotate_idx(s, stack_a, hold_second_idx);
            else if (hold_first_idx > middle_of_list && hold_second_idx > middle_of_list)
                reverse_rotate_idx(s, stack_a, hold_second_idx);
            find_place_in_b(s, stack_a, stack_b);
        }
        // ft_printf("chunk: %d\n", chunk);
        chunk++;
    }
}

// 44 77 28 36 56 74 78 60 30 47 35 46 2 59 8 82 24 51 57 94 18 33 4 22 73 81 90 25 31 98 48 54 72 15 9 23 1 68 92 14 63 40 86 10 61 17 12 88 50 84 45 37 5 34 75 100 52 26 70 91 89 7 96 20 85 95 49 71 6 13 79 19 99 53 69 38 27 11 41 67 21 83 39 62 87 43 32 29 76 65 93 55 58 16 3 80 64 97 42 66

//       "args": [
//     "44", "77", "28", "36", "56", "74", "78", "60", "30", "47", "35", "46", "2", "59", "8", "82", "24", "51", "57", "94", "18", "33", "4", "22", "73", "81", "90", "25", "31", "98", "48", "54", "72", "15", "9", "23", "1", "68", "92", "14", "63", "40", "86", "10", "61", "17", "12", "88", "50", "84", "45", "37", "5", "34", "75", "100", "52", "26","70", "91", "89", "7", "96", "20", "85", "95", "49", "71", "6", "13", "79", "19", "99", "53", "69", "38", "27", "11", "41", "67", "21", "83", "39", "62", "87", "43", "32", "29", "76", "65", "93", "55", "58", "16", "3", "80", "64", "97", "42", "66" 
    //   ],