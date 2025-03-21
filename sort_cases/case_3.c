/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:58:14 by apple             #+#    #+#             */
/*   Updated: 2025/03/21 17:31:05 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *next_num(t_stack **stack)
{
    t_stack *temp;

    temp = *stack;
    while (temp->next)
        temp = temp->next;
    return (temp);
}

int stack_b_is_sorted(t_stack **stack)
{
    t_stack	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->data < temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void find_place_in_b(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current_a;
    t_stack *current_b;

    if (s->b_size == 0)
    {
        push_b(s, stack_a, stack_b);
        return ;
    }
    current_a = *stack_a;
    current_b = *stack_b;
    if (current_a->data > current_b->data)
    {
        push_b(s, stack_a, stack_b);
        return ;
    }
    else if (current_a->data < next_num(stack_b)->data)
    {
        push_b(s, stack_a, stack_b);
        rotate_b(stack_b);
    }
    else if (current_a->data < current_b->data)
    {
        current_b = *stack_b;
        while (current_b && !(current_a->data < current_b->data && current_a->data > current_b->next->data))
        {
            rotate_b(stack_b);
            current_b = *stack_b;
        }
        push_b(s, stack_a, stack_b);
        swap_b(stack_b);
        if (stack_b_is_sorted(stack_b))
            return ;
        else
        {
            current_b = *stack_b;
            while (current_b->next)
                current_b = current_b->next;
            while (current_b && current_b->data < current_b->prev->data)
            {
                reverse_rotate_b(stack_b);
                current_b = next_num(stack_b);
            }
            if (current_b->data > current_b->prev->data)
                reverse_rotate_b(stack_b);
            return ;
        }
    }
}

void case_3(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp_a;
    int hold_first;
    int hold_second;
    int hold_first_idx;
    int hold_second_idx;
    int count_to_zero;
    int count_to_max;
    int chunk_size;
    int chunk_min;
    int chunk_max;
    int chunk;
    int i;

    chunk_size = s->a_size / 5;
    chunk = 0;
    while (chunk < 5)
    {
        chunk_min = chunk * chunk_size;
        chunk_max = chunk_min + chunk_size - 1;

        int j = chunk_min;
        while (j <= chunk_max)
        {
            hold_first = find_hold_first(stack_a, chunk_min, chunk_max);
            hold_second = find_hold_second(stack_a, chunk_min, chunk_max);
            if (!hold_first)
            {
                ft_printf("break first.\n");
                break ;
            }
            if (!hold_second)
            {
                ft_printf("break second.\n");
                break ;
            }
            i = 0;
            temp_a = *stack_a;
            while (temp_a)
            {
                if (temp_a->data == hold_first)
                    hold_first_idx = i;
                if (temp_a->data == hold_second)
                    hold_second_idx = i;
                i++;
                temp_a = temp_a->next;
            }
            count_to_max = find_count_to_max(s, hold_second_idx);
            count_to_zero = find_count_to_zero(hold_first_idx);
            
            if (count_to_zero > count_to_max)
                reverse_rotate_idx(s, stack_a, hold_second_idx);
            else
                rotate_idx(stack_a, hold_first_idx);
            find_place_in_b(s, stack_a, stack_b);
            j++;
        }
        chunk++;
    }
    if (s->a_size > 0)
        find_place_in_b(s, stack_a, stack_b);
}

// 44 77 28 36 56 74 78 60 30 47 35 46 2 59 8 82 24 51 57 94 18 33 4 22 73 81 90 25 31 98 48 54 72 15 9 23 1 68 92 14 63 40 86 10 61 17 12 88 50 84 45 37 5 34 75 100 52 26 70 91 89 7 96 20 85 95 49 71 6 13 79 19 99 53 69 38 27 11 41 67 21 83 39 62 87 43 32 29 76 65 93 55 58 16 3 80 64 97 42 66

//       "args": [
//     "44", "77", "28", "36", "56", "74", "78", "60", "30", "47", "35", "46", "2", "59", "8", "82", "24", "51", "57", "94", "18", "33", "4", "22", "73", "81", "90", "25", "31", "98", "48", "54", "72", "15", "9", "23", "1", "68", "92", "14", "63", "40", "86", "10", "61", "17", "12", "88", "50", "84", "45", "37", "5", "34", "75", "100", "52", "26","70", "91", "89", "7", "96", "20", "85", "95", "49", "71", "6", "13", "79", "19", "99", "53", "69", "38", "27", "11", "41", "67", "21", "83", "39", "62", "87", "43", "32", "29", "76", "65", "93", "55", "58", "16", "3", "80", "64", "97", "42", "66" 
    //   ],