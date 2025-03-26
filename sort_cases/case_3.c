/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:58:14 by apple             #+#    #+#             */
/*   Updated: 2025/03/26 17:39:29 by apple            ###   ########.fr       */
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

    // if (!stack_b || !(*stack_b))
    //     return 0;
    
    // ft_printf("in sort_stack_b:\n");
    if (num > find_max(stack_b))
    {
        current = *stack_b;
        // ft_printf("(num > find_max(stack_b): %d\n", current->data);
        while (current && current->data != find_max(stack_b))
        {
            current = current->next;
            moves++;
        }
        return (moves);
    }
    else if (num < find_min(stack_b))
    {
        current = *stack_b;
        // ft_printf("num < find_min(stack_b): %d\n", current->data);
        while (current && current->data != find_min(stack_b))
        {
            current = current->next;
            moves++;
        }
        moves += 1;
        return (moves);
    }
    else
    {
        current = *stack_b;
        // ft_printf("current->data: %d\n", current->data);
        while (current->next)
        {
            // ft_printf("sort_stack_b_current_data: %d\n", current->data);
            // ft_printf("num: %d\n", num);
            // ft_printf("current->next->data: %d\n", current->next->data);
            if (num < current->data && num > current->next->data)
                break;
            current = current->next;
            moves++;
        }
        return (moves += 1);
    }
    return (0);
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

void sort_stack_b(t_size *s, t_stack **stack_a, t_stack **stack_b, t_cost cheapest)
{
    int moves;

    if (!stack_a || !stack_b)
        return ;
    (void)s;
    if (cheapest.rb_moves <= cheapest.rrb_moves)
        moves = cheapest.rb_moves;
    else
        moves = cheapest.rrb_moves;
    // moves = cheapest.move_b;
    if (moves < 0)
        moves *= -1;
    // ft_printf("moves: %d\n", moves);
    if (cheapest.rb_moves <= cheapest.rrb_moves)
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

int count_moves_a(t_size *s, t_stack **stack_a, int data)
{
    int moves_a;
    int ra;
    int rra;
    
    ra = find_count_to_zero(stack_a, data);
    rra = s->a_size - ra;
    if (ra < rra)
        moves_a = ra;
    else
        moves_a = rra;
    return (moves_a);
}

int count_moves_b(t_size *s, t_stack **stack_b, int data)
{
    s->rb_moves = find_place_in_b(stack_b, data);
    return (s->rb_moves);
}

void move_num_on_top(t_cost cheapest, t_size *s, t_stack **stack_a)
{
    if (cheapest.index <= (s->a_size / 2))
    {
        rotate_idx(stack_a, cheapest.index);
    }
    else
        reverse_rotate_idx(s, stack_a, cheapest.index);
}

void final_rotate(t_stack **stack_b)
{
    int max_num = find_max(stack_b);
    while ((*stack_b)->data != max_num)
    {
        rotate_b(stack_b);
    }
}

void find_cheapest_number(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;
    t_cost cheapest;
    int moves_a;
    // int moves_b;
    int total_cost;

    cheapest.cost = INT_MAX;
    int i = 0;
    temp = *stack_a;
    while (temp)
    {
        // ft_printf("stack_size: %d\n", s->a_size);
        if (!*stack_a)
            return ;
        moves_a = count_moves_a(s, stack_a, temp->data);
        // moves_b = count_moves_b(s, stack_b, temp->data);
        // ft_printf("stack_b in find_cheapest_number: \n");
        // t_stack *current = *stack_b;
        // while (current)
        // {
        //     ft_printf("%d ", current->data);
        //     current = current->next;
        // }
        // ft_printf("\n");
        s->rb_moves = count_moves_b(s, stack_b, temp->data);
        if (s->b_size == 0)
            s->rrb_moves = 0;
        else
            s->rrb_moves = s->b_size - s->rb_moves;
        // ft_printf("temp->data: %d\n", temp->data);
        // ft_printf("s->rb_moves: %d\n", s->rb_moves);
        // ft_printf("s->rrb_moves: %d\n", s->rrb_moves);
        if (s->rb_moves <= s->rrb_moves)
            total_cost = s->rb_moves + moves_a;
        else
            total_cost = s->rrb_moves + moves_a;
        // ft_printf("total_cost: %d\n", total_cost);
        if (total_cost < cheapest.cost)
        {
            cheapest.index = i;
            cheapest.cost = total_cost;
            cheapest.move_a = moves_a;
            cheapest.rb_moves = s->rb_moves;
            cheapest.rrb_moves = s->rrb_moves;
            // cheapest.move_b = moves_b;
        }
        i++;
        temp = temp->next;
    }
    // ft_printf("cheapest.index: %d\n", cheapest.index);
    // ft_printf("cheapest.move_a: %d\n", cheapest.move_a);
    // ft_printf("cheapest.move_b: %d\n", cheapest.move_b);
    move_num_on_top(cheapest, s, stack_a);
    sort_stack_b(s, stack_a, stack_b, cheapest);
    push_b(s, stack_a, stack_b);
    final_rotate(stack_b);
    // printf_stack(*stack_a, *stack_b);
}

void case_3(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    while (s->a_size > 0)
    {
        find_cheapest_number(s, stack_a, stack_b);
    }
    // ft_printf("in\n");
    // case_1(stack_a);
    // if (!stack_b_is_sorted(stack_b) && find_min_idx(stack_b, find_min(stack_b)) <= (s->b_size / 2))
    // {
    //     while (!stack_b_is_sorted(stack_b))
    //         rotate_b(stack_b);
    // }
    // else if (!stack_b_is_sorted(stack_b) && find_min_idx(stack_b, find_min(stack_b)) > (s->b_size / 2))
    // {
    //      while (!stack_b_is_sorted(stack_b))
    //         reverse_rotate_b(stack_b);
    // }
}
