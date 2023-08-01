/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:07:04 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/01 23:51:28 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_len(t_node *stack)
{
	size_t	len;
	t_node	*current;

	if (stack == NULL)
		return (0);
	len = 1;
	current = stack->next;
	while (current != NULL && current != stack)
	{
		len++;
		current = current->next;
	}
	return (len);
}

int	is_sorted(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current != NULL && current->next != stack)
	{
		if ((current->num) > (current->next->num))
			return (0);
		current = current->next;
	}
	return (1);
}

long int	ft_abs(long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	get_min(t_node *stack)
{
	int		min;
	t_node	*current;

	min = INT_MAX;
	if (stack->num <= min)
		min = stack->num;
	current = stack->next;
	while (current != NULL && current != stack)
	{
		if (current->num < min)
			min = current->num;
		current = current->next;
	}
	return (min);
}

int	get_max(t_node *stack)
{
	int		max;
	t_node	*current;

	max = INT_MIN;
	if (stack->num >= max)
		max = stack->num;
	current = stack->next;
	while (current != NULL && current != stack)
	{
		if (current->num > max)
			max = current->num;
		current = current->next;
	}
	return (max);
}
