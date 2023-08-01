/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_split_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:46:29 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/01 23:46:42 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static void	get_centers_num(t_node *stack_a, int *sp_num)
{
	int		*num;
	size_t	len;
	size_t	i;

	i = 1;
	len = stack_len(stack_a);
	num = malloc(sizeof(int) * len);
	if (num == NULL)
		exit(1);
	num[0] = get_min(stack_a);
	while (i < len)
	{
		num[i] = get_min_more(stack_a, num[i - 1]);
		i++;
	}
	sp_num[0] = num[len / 4];
	sp_num[1] = num[len / 2];
	sp_num[2] = num[(len / 4) * 3];
	free(num);
}

static void	groping_last(t_node **stack_a, t_node **stack_b, int mid)
{
	while (*stack_a != NULL)
	{
		if ((*stack_a)->num < mid)
			pb(stack_a, stack_b);
		else
			pb_rb(stack_a, stack_b);
	}
}

static void	groping(t_node **stack_a, t_node **stack_b)
{
	size_t	count;
	int		*sp_num;
	size_t	len;

	sp_num = malloc(sizeof(int) * 3);
	if (sp_num == NULL)
		exit(1);
	get_centers_num(*stack_a, sp_num);
	len = stack_len(*stack_a);
	count = 0;
	while (count <= len)
	{
		if ((*stack_a)->num < sp_num[0])
			pb(stack_a, stack_b);
		else if ((*stack_a)->num >= sp_num[0] && (*stack_a)->num < sp_num[1])
			pb_rb(stack_a, stack_b);
		else
			ra(stack_a);
		count++;
	}
	groping_last(stack_a, stack_b, sp_num[2]);
	free(sp_num);
}

static int	len_to_max(t_node *stack, int max)
{
	size_t	count;

	count = 0;
	if (stack->num == max)
		return (0);
	while (stack->num != max)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	sort_split_insert_old(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	len;
	int	distance;

	groping(stack_a, stack_b);
	max = 0;
	len = 0;
	if (*stack_b == NULL)
		return ;
	while (*stack_b)
	{
		len = stack_len(*stack_b);
		max = get_max(*stack_b);
		distance = len_to_max(*stack_b, max);
		while ((*stack_b)->num != max)
		{
			if (distance < len / 2)
				rb(stack_b);
			else if (len / 2 <= distance)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
