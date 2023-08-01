/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_new_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:46:29 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/01 23:53:34 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void printList(t_node *head)
{
    t_node *current = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
// hode
    do
    {
        printf("%d ", current->num);
        current = current->next;
    } while (current != head);

    printf("\n");
}

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
	i = 0;
	while (i < (n - 1))
	{
		sn[i] = num[(len / n) * (i + 1)];
		i++;
	}
	sn[n - 1] = INT_MAX;
	// printf("sn:\n");
	// 	printf("%d\n", sn[2]);
	free(num);
}

void	push_to_b(t_node **s_a, t_node **s_b, int *sn)
{
	int		j;
	size_t	len;
	size_t	count;

	j = 0;
	count = 0;
	len = stack_len(*s_a);
	while (*s_a != NULL)
	{
			printf("J: %d\n", j);
		while (count < len)
		{
			if ((*s_a)->num <= sn[j])
				pb(s_a, s_b);
			else if ((*s_a)->num > sn[j] && (*s_a)->num <= sn[j + 1])
				pb_rb(s_a, s_b);
			else
				ra(s_a);
			count++;
		}
		j = j + 2;
		count = 0;
		len = stack_len(*s_a);
	}
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
	push_to_b(stack_a, stack_b, sn);
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
