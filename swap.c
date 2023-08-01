/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:10:57 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/21 17:48:48 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_node **head)
{
	int	temp;

	if (*head == NULL)
		return ;
	temp = (*head)->num;
	(*head)->num = (*head)->next->num;
	(*head)->next->num = temp;
}

void	sa(t_node **head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	sb(t_node **head)
{
	swap(head);
	write(1, "sb\n", 3);
}

void	ss(t_node **list_a, t_node **list_b)
{
	swap(list_a);
	swap(list_b);
	write(1, "ss\n", 3);
}
