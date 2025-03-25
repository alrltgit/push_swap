// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   case_4.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/21 17:35:05 by apple             #+#    #+#             */
// /*   Updated: 2025/03/23 17:36:58 by apple            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../push_swap.h"

// int find_lowest(t_stack **stack_a)
// {
//     t_stack *temp;
//     int hold_first;

//     temp = *stack_a;
//     hold_first = temp->data;
//     while (temp)
//     {
//         if (temp->data < hold_first)
//         {
//             hold_first = temp->data;
//         }
//         temp = temp->next;
//     }
//     return (hold_first);
// }

// int find_highest(t_stack **stack_a)
// {
//     t_stack *temp;
//     int hold_first;

//     temp = *stack_a;
//     hold_first = temp->data;
//     while (temp)
//     {
//         if (temp->data > hold_first)
//         {
//             hold_first = temp->data;
//         }
//         temp = temp->next;
//     }
//     return (hold_first);
// }

// int find_lowest_to_zero(int hold_first_idx)
// {
//     int count_to_zero;
    
//     count_to_zero = 0;
//     while (count_to_zero < hold_first_idx)
//         count_to_zero++;
//     return (count_to_zero);
// }

// int find_lowest_to_max(t_size *s, int hold_second_idx)
// {
//     int count_to_max;
//     int temp;

//     count_to_max = 0;
//     temp = hold_second_idx;
//     while (temp < s->a_size)
//     {
//         temp++;
//         count_to_max++;
//     }
//     return (count_to_max);
// }

// void case_4(t_size *s, t_stack **stack_a, t_stack **stack_b)
// {
//     int chunk;
//     int num_chunks;
//     long chunk_size;
//     t_stack *temp;
//     int lowest_idx = 0;
//     int lowest_to_max;
//     int lowest_to_zero;
    
//     num_chunks = 0;
//     if (s->a_size <= 20)
//         num_chunks = 2;
//     else if (s->a_size <= 50)
//         num_chunks = 4;
//     else if (s->a_size <= 100)
//         num_chunks = 5;
//     else if (s->a_size <= 200)
//         num_chunks = 8;
//     else if (s->a_size <= 300)
//         num_chunks = 10;
//     else if (s->a_size <= 400)
//         num_chunks = 12;
//     else
//         num_chunks = 15;

//     chunk_size = s->a_size / num_chunks;
//     chunk = 0;
//     while (chunk < num_chunks)
//     {
//         int min = chunk * chunk_size;
//         int max = chunk_size + min - 1;
//         int j = min;
//         while (j <= max)
//         {
//             int lowest = find_lowest(stack_a);
//             if (!lowest)
//             {
//                 ft_printf("Lowest number is not found.\n");
//                 return ;
//             }
//             temp = *stack_a;
//             int i = 0;
//             while (temp)
//             {
//                 if (temp->data == lowest)
//                     lowest_idx = i;
//                 temp = temp->next;
//                 i++;
//             }
//             lowest_to_zero = find_lowest_to_zero(lowest_idx);
//             lowest_to_max = find_lowest_to_max(s, lowest_idx);
//             if (lowest_to_zero > lowest_to_max)
//                 reverse_rotate_idx(s, stack_a, lowest_idx);
//             else
//                 rotate_idx(stack_a, lowest_idx);
//             push_b(s, stack_a, stack_b);
//             j++;
//         }
//         chunk++;
//     }
//     while (s->a_size > 0)
//     {
//         int lowest = find_lowest(stack_a);
//         int i = 0;
//         int idx = 0;
//         temp = *stack_a;
//         while (temp)
//         {
//             if (temp->data == lowest)
//                 idx = i;
//             temp = temp->next;
//             i++;
//         }
//         rotate_idx(stack_a, idx);
//         push_b(s, stack_a, stack_b);
//     }
// }
