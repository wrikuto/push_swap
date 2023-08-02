/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:12:48 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/02 15:13:19 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

long	ps_atol(const char *str)
{
	int		i;
	long	sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1 + ((str[i] == '-') * -2);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ('0' <= str[i] && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (((num > LONG_MAX / 10) && ft_isdigit(str[i]) == 1) || \
			((num == LONG_MAX / 10) && str[i] > (LONG_MAX % 10) + '0'))
			return (INT_MAX + 3L);
	}
	return (num * sign);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}
