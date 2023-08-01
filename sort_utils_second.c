/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:46:36 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/01 19:20:05 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_rb(t_node **stack_a, t_node **stack_b)
{
	pb(stack_a, stack_b);
	rb(stack_b);
}

int	list_average(t_node	*stack)
{
	size_t	i;
	size_t	len;
	int		num;

	i = 0;
	num = 0;
	len = stack_len(stack);
	while (i < len)
	{
		num = num + stack->num;
		stack = stack->next;
		i++;
	}
	return (num / len);
}

int	get_min_more(t_node *stack, int n)
{
	int		min;
	t_node	*current;

	min = INT_MAX;
	if (stack->num <= min && stack->num > n)
		min = stack->num;
	current = stack->next;
	while (current != NULL && current != stack)
	{
		if (current->num <= min && current->num > n)
			min = current->num;
		current = current->next;
	}
	return (min);
}
