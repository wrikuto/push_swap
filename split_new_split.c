/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_new_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:46:29 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/01 22:21:06 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static void	get_cep_num(t_node *stack_a, int *sn, size_t n)
{
	int			*num;
	size_t		len;
	size_t		i;

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
	i = -1;
	while (i++ < n - 1)
		sn[i] = num[len / (n * (i + 1))];
	sn[n - 1] = INT_MAX;
	for (i = 0; i < len; i++)
		printf("%d\n", num[i]);
	free(num);
}

void	push_to_b(t_node **stack_a, t_node **stack_b, size_t n, int *sn)
{
	int		j;
	size_t	len;
	size_t	count;
	size_t	push_count;

	j = 0;
	count = 0;
	len = stack_len(*stack_a);
	while (*stack_a)
	{
		while (count < len)
		{
			if ((*stack_a)->num <= sn[j * 2])
				pb(stack_a, stack_b);
			else if ((*stack_a)->num > sn[j * 2] && (*stack_a)->num <= sn[j * 2 + 1])
				pb_rb(stack_a, stack_b);
			else
				ra(stack_a);
			count++;
		}
		j++;
		count = 0;
		len = stack_len(*stack_a);
	}
	grope_last(stack_a, stack_b, sn[n - 2])
}

static void	groping(t_node **stack_a, t_node **stack_b)
{
	size_t	n;
	int		*sn;
	size_t	len;

	len = stack_len(*stack_a);
	if (len < 100)
		n = 4;
	else
		n = 4 * (len / 100);
	sn = malloc(sizeof(int) * n);
	if (sn == NULL)
		exit(1);
	get_cep_num(*stack_a, sn, n);
	push_to_b(stack_a, stack_b, n, sn);
	free(sn);
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

void	sort_split_insert(t_node **stack_a, t_node **stack_b)
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
