/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:58:14 by apple             #+#    #+#             */
/*   Updated: 2025/03/24 22:50:41 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int find_max(t_stack **stack)
{
    t_stack *current;
    int max;

    if (!stack || !(*stack))
        return (-2147483648);

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

int find_min_idx(t_stack **stack, int min_val)
{
    t_stack *current;
    int idx;
    
    idx = 0;
    current = *stack;
    while (current)
    {
        if (current->data == min_val)
            break ;
        idx++;
    }
    return (idx);
}

int find_min(t_stack **stack)
{
    t_stack *current;
    int min;

    if (!stack || !(*stack))
        return (2147483647);

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
        return 0;
    
    current = *stack_b;
    if (num > find_max(stack_b))
    {
        while (current && current->data != find_max(stack_b))
        {
            current = current->next;
            moves++;
        }
        return (moves);
    }
    current = *stack_b;
    if (num < find_min(stack_b))
    {
        while (current && current->data != find_min(stack_b))
        {
            current = current->next;
            moves++;
        }
        moves += 1;
        return (moves);
    }
    current = *stack_b;
    while (current->next)
    {
        ft_printf("current->data: %d\n", current->data);
        ft_printf("num: %d\n", num);
        ft_printf("current->next->data: %d\n", current->next->data);
        if (num < current->data && num > current->next->data)
            break;
        current = current->next;
        moves++;
    }
    return (moves + 1);
}

int find_place_in_b_2(t_stack **stack_b, int num)
{
    t_stack *current;
    int moves = 0;

    if (!stack_b || !(*stack_b))
        return 0;
    
    current = *stack_b;
    while (current->next)
        current = current->next;
    if (num > find_max(stack_b))
    {
        while (current && current->prev && current->data != find_max(stack_b))
        {
            current = current->prev;
            moves++;
        }
        moves += 1;
        return (moves);
    }
    current = *stack_b;
    while (current->next)
        current = current->next;
    if (num < find_min(stack_b))
    {
        while (current && current->prev && current->data != find_min(stack_b))
        {
            current = current->prev;
            moves++;
        }
        return (moves);
    }
    current = *stack_b;
    while (current->next)
        current = current->next;
    while (current && current->prev)
    {
        if (num > current->data && num < current->prev->data)
            break;
        current = current->prev;
        moves++;
    }
    return (moves + 1);
}

void sort_stack_b(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    int moves;

    if (!stack_a || !stack_b)
        return ;
    // t_stack *temp = *stack_a;
    int num = (*stack_a)->data;
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
        while (moves > 0)
        {
            reverse_rotate_b(stack_b);
            moves--;
        }
    }
}

void find_cheapest_number(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;
    t_cost cheapest;
    int moves_a;
    int moves_b;

    cheapest.cost = INT_MAX;
    temp = *stack_a;
    int i = 0;
    while (temp)
    {
        ft_printf("stack_size: %d\n", s->a_size);
        if (!*stack_a)
            return ;
        ft_printf("temp->data: %d\n", temp->data);
        int ra_a = find_count_to_zero(stack_a, temp->data);
        ft_printf("ra_a: %d\n", ra_a);
        int rra_a = s->a_size - ra_a;
        ft_printf("rra_a: %d\n", rra_a);
        if (ra_a < rra_a)
            moves_a = ra_a;
        else
            moves_a = rra_a;
        int ra_b = find_place_in_b(stack_b, temp->data);
        ft_printf("ra_b: %d\n", ra_b);
        int rra_b = find_place_in_b_2(stack_b, temp->data);
        ft_printf("rra_b: %d\n", rra_b);
        if (ra_b < rra_b)
            moves_b = ra_b;
        else
            moves_b = rra_b;
        ft_printf("moves_a: %d\n", moves_a);
        ft_printf("moves_b: %d\n", moves_b);
        int total_cost = moves_a + moves_b;
        ft_printf("total_cost: %d\n", total_cost);
        if (total_cost < cheapest.cost)
        {
            cheapest.index = i;
            cheapest.cost = total_cost;
            cheapest.move_a = moves_a;
            cheapest.move_b = moves_b;
            ft_printf("cheapest.index: %d\n", cheapest.index);
            ft_printf("cheapest.cost: %d\n", cheapest.cost);
            ft_printf("in\n");
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
    push_b(s, stack_a, stack_b);
    printf_stack(*stack_a, *stack_b);
}

void case_3(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_a)
    {
        find_cheapest_number(s, stack_a, stack_b);
    }
    if (!stack_b_is_sorted(stack_b) && find_min_idx(stack_b, find_min(stack_b)) <= (s->b_size / 2))
    {
        while (!stack_b_is_sorted(stack_b))
            rotate_b(stack_b);
    }
    else if (!stack_b_is_sorted(stack_b) && find_min_idx(stack_b, find_min(stack_b)) > (s->b_size / 2))
    {
         while (!stack_b_is_sorted(stack_b))
            reverse_rotate_b(stack_b);
    }
}