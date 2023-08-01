/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_four.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:27:56 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/01 16:00:14 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*rtn_first(t_node	*stack_a)
{
	int		min;
	t_node	*first_pointer;
	t_node	*current;

	min = stack_a->num;
	first_pointer = stack_a;
	current = stack_a->next;
	while (current != stack_a)
	{
		if ((current->num) < min)
		{
			min = current->num;
			first_pointer = current;
		}
		current = current->next;
	}
	return (first_pointer);
}

static t_node	*rtn_second(t_node	*stack_a, t_node *first_pointer)
{
	int		second_min;
	t_node	*second_pointer;
	t_node	*current;

	second_pointer = stack_a;
	second_min = INT_MAX;
	current = stack_a->next;
	while (current != stack_a)
	{
		if ((current->num) < second_min && current != first_pointer)
		{
			second_min = current->num;
			second_pointer = current;
		}
		current = current->next;
	}
	if ((current->num) < second_min && current != first_pointer)
		second_pointer = current;
	return (second_pointer);
}

static int	dif_from_head(t_node *stack_a, t_node *first_min)
{
	int		i;
	t_node	*current;

	if (stack_a == NULL || stack_a == first_min)
		return (0);
	i = 1;
	current = (stack_a)->next;
	while (current != stack_a && current != first_min)
	{
		current = current->next;
		i++;
	}
	return (i);
}

static void	second_pb(t_node **stack_a, t_node **stack_b, t_node *second_min)
{
	while (second_min != *stack_a)
		ra(stack_a);
	pb(stack_a, stack_b);
}

void	sort_five_or_four(t_node **stack_a, t_node **stack_b, int count)
{
	t_node	*first_min;
	t_node	*second_min;

	first_min = rtn_first(*stack_a);
	second_min = rtn_second(*stack_a, first_min);
	if (dif_from_head(*stack_a, first_min) <= 2)
	{
		while (first_min != *stack_a)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (first_min != *stack_a)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	if (count == 5)
		second_pb(stack_a, stack_b, second_min);
	sort_three_elements(stack_a);
	pa(stack_a, stack_b);
	if (count == 5)
		pa(stack_a, stack_b);
}
