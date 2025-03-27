/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fulfil_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:30:36 by apple             #+#    #+#             */
/*   Updated: 2025/03/27 15:13:12 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

t_stack	*ft_new(int data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*ft_add_back(t_stack **head, int data)
{
	t_stack	*next_node;
	t_stack	*temp;

	next_node = ft_new(data);
	if (!next_node)
	{
		ft_printf("Next_node wasn't created");
		return (NULL);
	}
	if (!*head)
	{
		*head = next_node;
		return (*head);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = next_node;
	next_node->prev = temp;
	return (*head);
}
