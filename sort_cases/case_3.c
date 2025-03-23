/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:58:14 by apple             #+#    #+#             */
/*   Updated: 2025/03/23 22:27:04 by apple            ###   ########.fr       */
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

// void find_place_in_b_2(t_size *s, t_stack **stack_a, t_stack **stack_b)
// {
//     t_stack *current_a;
//     t_stack *current_b;

//     // printf_stack(*stack_a, *stack_b);
//     if (s->b_size == 0)
//     {
//         push_b(s, stack_a, stack_b);
//         return ;
//     }
//     current_a = *stack_a;
//     current_b = *stack_b;
//     // ft_printf("current_b->data: %d\n", current_b->data);
//     // ft_printf("current_a->data: %d\n", current_a->data);
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
//             {
//                 reverse_rotate_b(stack_b);
//             }
//             return ;
//         }
//     }
// }

int find_max(t_stack **stack)
{
    t_stack *current;
    int max;

    if (!stack || !(*stack))
        return (-2147483648); // Return INT_MIN if the stack is empty

    current = *stack;
    max = current->data;

    while (current)
    {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }
    return max;
}

int find_min(t_stack **stack)
{
    t_stack *current;
    int min;

    if (!stack || !(*stack))
        return (2147483647); // Return INT_MAX if the stack is empty

    current = *stack;
    min = current->data;

    while (current)
    {
        if (current->data < min)
            min = current->data;
        current = current->next;
    }
    return min;
}

int find_place_in_b(t_stack **stack_b, int num)
{
    t_stack *current;
    int moves = 0;

    if (!stack_b || !(*stack_b))
        return 0; // If stack_b is empty, return 0 (insert at the beginning)
    
    current = *stack_b;

    // If the number is the new max or min, it should be placed after the max
    if (num > find_max(stack_b) || num < find_min(stack_b))
    {
        while (current->next && current->data != find_max(stack_b))
        {
            current = current->next;
            moves++;
        }
        return (moves + 1); // Place after the max value
    }

    // Otherwise, find the correct position where num fits between two nodes
    current = *stack_b;
    while (current->next)
    {
        if (num > current->data && num < current->next->data)
            break;
        current = current->next;
        moves++;
    }
    return (moves);
}

void sort_stack_b(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    int moves;

    if (!stack_a || !stack_b)
        return ;
    int num = (*stack_a)->data;
    printf_stack(*stack_a, *stack_b);
    ft_printf("num: %d\n", num);
    moves = find_place_in_b(stack_b, num);
    ft_printf("moves: %d\n", moves);
    if (moves <= s->b_size / 2)
    {
        while (moves > 0)
        {
            rotate_b(stack_b);
            moves--;
        }
    }
    else
    {
        moves = s->b_size - moves;
        while (moves > 0)
        {
            reverse_rotate_b(stack_b);
            moves--;
        }
    }
    push_b(s, stack_a, stack_b);
}

void find_cheapest_number(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;
    t_cost cheapest;
    int moves_a;
    int moves_b;

    cheapest.cost = INT_MAX;
    temp = *stack_a;
    // printf_stack(*stack_a, *stack_b);
    int i = 0;
    while (temp)
    {
        if (!*stack_a)
            return ;
        int ra_a = find_count_to_zero(stack_a, temp->data);
        int rra_a = s->a_size - ra_a;
        if (ra_a < rra_a)
            moves_a = ra_a;
        else
            moves_a = rra_a;
        int ra_b = find_place_in_b(stack_b, temp->data);
        int rra_b = s->b_size - ra_b;
        if (ra_b < rra_b)
            moves_b = ra_b;
        else
            moves_b = rra_b;
        int total_cost = moves_a + moves_b;
        // ft_printf("i: %d\n", i);
        // ft_printf("temp->data: %d\n", temp->data);
        if (total_cost < cheapest.cost)
        {
            cheapest.index = i;
            cheapest.cost = total_cost;
            cheapest.move_a = moves_a;
            cheapest.move_b = moves_b;
        }
        i++;
        temp = temp->next;
    }
    if (cheapest.index <= (s->a_size / 2))
    {
        rotate_idx(stack_a, cheapest.index);
    }
    else
        reverse_rotate_idx(s, stack_a, cheapest.index);
    sort_stack_b(s, stack_a, stack_b);
}

void case_3(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    // t_stack *temp;
    int i = 0;
    // temp = *stack_a;
    i = s->a_size;
    while (i > 0)
    {
        find_cheapest_number(s, stack_a, stack_b);
        i--;
        ft_printf("i: %d\n", i);
        // temp = temp->next;
    }
}