/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:02:46 by apple             #+#    #+#             */
/*   Updated: 2025/03/25 10:06:05 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_max(t_stack **stack)
{
	long	max;
	t_stack	*temp;
	t_stack	*max_node;

	temp = *stack;
	if (!temp)
		return (NULL);
	max = LONG_MIN;
	while (temp)
	{
		if (temp->data > max)
		{
			max = temp->data;
			max_node = temp;
		}
		temp = temp->next;
	}
	return (max_node);
}

t_stack	*get_min(t_stack **stack)
{
	long	min;
	t_stack	*temp;
	t_stack	*min_node;

	temp = *stack;
	if (!temp)
		return (NULL);
	min = LONG_MAX;
	while (temp)
	{
		if (temp->data < min)
		{
			min = temp->data;
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

void	assign_index(int stack_size, t_stack **stack)
{
	int		i;
	int		medium;
	t_stack	*temp;

	i = 0;
	temp = (*stack);
	if (!temp)
		return ;
	medium = stack_size / 2;
	while (temp)
	{
		temp->index = i;
		if (i <= medium)
		    temp->above_medium = true;
		else
			temp->above_medium = false;
		temp = temp->next;
		i++;
	}
}

void	set_target_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*target;
	long	best_match;

	temp_a = *stack_a;
	while (temp_a)
	{
		best_match = LONG_MIN;
		temp_b = *stack_b;
		while (temp_b)
		{
			if (temp_b->data < temp_a->data && temp_b->data > best_match)
			{
				best_match = temp_b->data;
				target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (best_match == LONG_MIN)
			temp_a->target = get_max(stack_b);
		else
			temp_a->target = target;
		temp_a = temp_a->next;
	}
}

void	set_target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*target;
	long	best_match;

	temp_b = *stack_b;
	while (temp_b)
	{
		best_match = LONG_MAX;
		temp_a = *stack_a;
		while (temp_a)
		{
			if (temp_a->data > temp_b->data && temp_a->data < best_match)
			{
				best_match = temp_a->data;
				target = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (best_match == LONG_MAX)
			temp_b->target = get_min(stack_a);
		else
			temp_b->target = target;
		temp_b = temp_b->next;
	}
}

void	count_cost_a(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
	int		a_size;
	int		b_size;
	t_stack	*temp_a;

    (void)stack_b;
	a_size = s->a_size;
	b_size = s->b_size;
	temp_a = *stack_a;
	while (temp_a)
	{
		(temp_a)->push_cost = (temp_a)->index;
		if (!(temp_a->above_medium))
			temp_a->push_cost = a_size - (temp_a->index);
		if (temp_a->target->above_medium)
			temp_a->push_cost += temp_a->target->index;
		else
			temp_a->push_cost += b_size - (temp_a->target->index);
		temp_a = temp_a->next;
	}
}

void	set_best_to_move(t_stack **stack)
{
	long	cheapest;
	t_stack	*best_to_move;
	t_stack	*temp;

	temp = *stack;
	if (!temp)
		return ;
	cheapest = LONG_MAX;
	while (temp)
	{
		if (temp->push_cost < cheapest)
		{
			cheapest = temp->push_cost;
			best_to_move = temp;
		}
		temp = temp->next;
	}
	best_to_move->cheapest = true;
}

void	get_stack_info(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    int a_size = s->a_size;
    int b_size = s->b_size;
	assign_index(a_size, stack_a);
	assign_index(b_size, stack_b);
	set_target_a(stack_a, stack_b);
	count_cost_a(s, stack_a, stack_b);
	set_best_to_move(stack_a);
}

t_stack	*find_best_to_move(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (!temp)
		return (NULL);
	while (temp)
	{
		if (temp->cheapest)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}


void	rotate_2(t_size *s, t_stack **stack_a, t_stack **stack_b, t_stack *best_to_move)
{
    int a_size = s->a_size;
    int b_size = s->b_size;
	while (*stack_a != best_to_move && *stack_b != best_to_move->target)
		rr(stack_a, stack_b);
	assign_index(a_size, stack_a);
	assign_index(b_size, stack_b);
}

void	rev_rotate_2(t_size *s, t_stack **stack_a, t_stack **stack_b, t_stack *best_to_move)
{
    int a_size = s->a_size;
    int b_size = s->b_size;
	while (*stack_a != best_to_move && *stack_b != best_to_move->target)
		rra_rrb(stack_a, stack_b);
	assign_index(a_size, stack_a);
	assign_index(b_size, stack_b);
}

void	check_top_nodes(t_stack **stack, t_stack *top, char name)
{
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->above_medium)
				rotate_a(stack);
			else
				reverse_rotate_a(stack);
		}
		else if (name == 'b')
		{
			if (top->above_medium)
				rotate_b(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

void	move_to_b(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best_to_move;

	best_to_move = find_best_to_move(stack_a);
	if (best_to_move->above_medium && best_to_move->target->above_medium)
		rotate_2(s, stack_a, stack_b, best_to_move);
	else if (!(best_to_move->above_medium)
		&& !(best_to_move->target->above_medium))
		rev_rotate_2(s, stack_a, stack_b, best_to_move);
	check_top_nodes(stack_a, best_to_move, 'a');
	check_top_nodes(stack_b, best_to_move->target, 'b');
	push_b(s, stack_a, stack_b);
}

void	tiny_sort(t_stack **stack)
{
	t_stack	*max;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	if ((*stack)->next->next == NULL)
	{
		if ((*stack)->data > (*stack)->next->data)
			swap_a(stack);
		return ;
	}
	max = get_max(stack);
	if (*stack == max)
		rotate_a(stack);
	else if ((*stack)->next == max)
		reverse_rotate_a(stack);
	if ((*stack)->data > (*stack)->next->data)
		swap_a(stack);
}

void	move_back_b(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
    int a_size = s->a_size;
    int b_size = s->b_size;
	assign_index(a_size, stack_a);
	assign_index(b_size, stack_b);
	set_target_b(stack_a, stack_b);
}

void	move_to_a(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
	check_top_nodes(stack_a, (*stack_b)->target, 'a');
	push_a(s, stack_a, stack_b);
}

void	min_on_top(t_stack **stack_a)
{
	t_stack	*temp;

	temp = get_min(stack_a);
	while ((*stack_a)->data != temp->data)
	{
		if (temp->above_medium)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
}

void	sort_stack(t_size *s, t_stack **stack_a, t_stack **stack_b)
{
	int	a_size;

	a_size = s->a_size;
	if (a_size-- > 3 && !argv_is_sorted(*stack_a))
		push_b(s, stack_a, stack_b);
	if (a_size-- > 3 && !argv_is_sorted(*stack_a))
		push_b(s, stack_a, stack_b);
	while (a_size-- > 3 && !argv_is_sorted(*stack_a))
	{
		get_stack_info(s, stack_a, stack_b);
		move_to_b(s, stack_a, stack_b);
	}
    case_1(stack_a);
	while (*stack_b)
	{
		move_back_b(s, stack_a, stack_b);
		move_to_a(s, stack_a, stack_b);
	}
	assign_index(a_size, stack_a);
	min_on_top(stack_a);
}