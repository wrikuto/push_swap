/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:34:00 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/02 17:04:38 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_sort(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (*stack_a == NULL || is_sorted(*stack_a))
		return ;
	if (len == 2 && ((*stack_a)->num) > ((*stack_a)->next->num))
		ra(stack_a);
	else if (len == 3)
		sort_three_elements(stack_a);
	else if (len == 4 || len == 5)
		sort_five_or_four(stack_a, stack_b, len);
	else
		quick_insert(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (chk_num_string(argv[1]) == 0 && argv[2] == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (chk_args(&argv[1]) == 0 && argv[2] != NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	create_list(&argv[1], &stack_a);
	select_sort(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
