/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:42:44 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/25 22:32:30 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*free_list(t_node **head)
{
	t_node	*current;
	t_node	*temp;

	if (*head == NULL)
		return (*head);
	current = *head;
	while (current->next != *head)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(current);
	*head = NULL;
	return (*head);
}

static t_node	*new_node(int res_num)
{
	t_node	*data;

	data = malloc(sizeof(t_node));
	if (data == NULL)
		return (NULL);
	data -> num = res_num;
	data -> next = NULL;
	data -> prev = NULL;
	return (data);
}

static t_node	*add_node(t_node **head, int num)
{
	t_node	*new;
	t_node	*current;

	new = new_node(num);
	if (new == NULL)
		return (free_list(head));
	if (*head == NULL)
	{
		*head = new;
		(*head)->next = *head;
		(*head)->prev = *head;
	}
	else
	{
		current = *head;
		while (current->next != *head)
			current = current->next;
		current->next = new;
		new->next = *head;
		new->prev = current;
		(*head)->prev = new;
	}
	return (*head);
}

void	create_list(char **argv, t_node **head)
{
	size_t	i;
	char	*pos;

	i = 0;
	pos = *argv;
	if (argv[0] && argv[1] == NULL)
	{
		while (*pos != '\0')
		{
			while (*pos == ' ')
				pos++;
			add_node(head, (int)string_atol(&pos));
			if (*head == NULL)
				return ;
		}
		return ;
	}
	while (argv[i] != NULL)
	{
		add_node(head, (int)ps_atol(argv[i]));
		if (*head == NULL)
			return ;
		i++;
	}
}
