/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:06:44 by wrikuto           #+#    #+#             */
/*   Updated: 2023/07/25 16:16:52 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chk_valid(char **argv)
{
	size_t	i;
	long	long_num;

	i = 0;
	long_num = 0;
	while (argv[i])
	{
		if (!(is_num(argv[i])))
			return (0);
		long_num = ps_atol(argv[i]);
		if (long_num < INT_MIN || INT_MAX < long_num)
			return (0);
		i++;
	}
	return (1);
}

static int	chk_dup(char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ps_atol(argv[i]) == ps_atol(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	chk_args(char **argv)
{
	if (chk_valid(argv) == 0)
		return (0);
	if (chk_dup(argv) == 0)
		return (0);
	return (1);
}
