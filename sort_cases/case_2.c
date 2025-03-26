/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:58:14 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 00:21:06 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

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
        return (0);

    current = *stack;
    max = current->data;

    while (current)
    {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }
    return (max);
}

int find_min(t_stack **stack)
{
    t_stack *current;
    int min;

    if (!stack || !(*stack))
        return (0);

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
    if (num > find_max(stack_b))
    {
        current = *stack_b;
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
        while (current->next)
        {
            if (num < current->data && num > current->next->data)
                break;
            current = current->next;
            moves++;
        }
        return (moves += 1);
    }
    return (0);
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
    if (moves < 0)
        moves *= -1;
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
        rotate_idx(stack_a, cheapest.index);
    else
        reverse_rotate_idx(s, stack_a, cheapest.index);
}

void final_rotate(t_size *s, t_stack **stack_a)
{
    int max_min;
    int max_idx;
    t_stack *temp;

    max_min = find_min(stack_a);
    temp = *stack_a;
    max_idx = 0;
    while (temp)
    {
        if (temp->data == max_min)
            break ;
        max_idx++;
        temp = temp->next;
    }
    s->ra_moves = max_idx;
    s->rra_moves = s->a_size - s->ra_moves;
    if (s->ra_moves <= s->rra_moves)
    {
        while ((*stack_a)->data != max_min)
            rotate_a(stack_a);
    }
    else
    {
        while ((*stack_a)->data != max_min)
            reverse_rotate_a(stack_a);
    }
}

void push_to_stack_a(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    while (s->b_size > 0)
        push_a(s, stack_a, stack_b);
}

void find_cheapest_number(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;
    t_cost cheapest;
    int moves_a;
    int total_cost;

    cheapest.cost = INT_MAX;
    int i = 0;
    temp = *stack_a;
    while (temp)
    {
        if (!*stack_a)
            return ;
        moves_a = count_moves_a(s, stack_a, temp->data);
        s->rb_moves = count_moves_b(s, stack_b, temp->data);
        if (s->b_size == 0)
            s->rrb_moves = 0;
        else
            s->rrb_moves = s->b_size - s->rb_moves;
        if (s->rb_moves <= s->rrb_moves)
            total_cost = s->rb_moves + moves_a;
        else
            total_cost = s->rrb_moves + moves_a;
        if (total_cost < cheapest.cost)
        {
            cheapest.index = i;
            cheapest.cost = total_cost;
            cheapest.move_a = moves_a;
            cheapest.rb_moves = s->rb_moves;
            cheapest.rrb_moves = s->rrb_moves;
        }
        i++;
        temp = temp->next;
    }
    move_num_on_top(cheapest, s, stack_a);
    sort_stack_b(s, stack_a, stack_b, cheapest);
    push_b(s, stack_a, stack_b);
    case_1(stack_a);
}

void case_2(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    while (s->a_size > 3)
        find_cheapest_number(s, stack_a, stack_b);
    while (s->b_size > 0)
        find_cheapest_number_a(s, stack_a, stack_b);
    final_rotate(s, stack_a);
}
