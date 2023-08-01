/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:39:05 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/31 02:14:28 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	src_join(t_node **src, t_node *next, t_node *last)
{
	if (*src == next)
	{
		*src = NULL;
	}
	else
	{
		*src = next;
		next->prev = last;
		last->next = next;
	}
}

void	push(t_node **src, t_node **dest)
{
	t_node	*src_next;
	t_node	*src_last;
	t_node	*dest_last;

	if (*src == NULL)
		return ;
	src_next = (*src)->next;
	src_last = (*src)->prev;
	if (*dest == NULL)
	{
		*dest = *src;
		(*dest)->next = *dest;
		(*dest)->prev = *dest;
		src_join(src, src_next, src_last);
		return ;
	}
	dest_last = (*dest)->prev;
	(*src)->next = *dest;
	(*src)->prev = dest_last;
	(*dest)->prev = *src;
	dest_last->next = *src;
	*dest = *src;
	src_join(src, src_next, src_last);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
