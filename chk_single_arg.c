/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_single_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:56:54 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/02 15:32:24 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	string_atol(char **str)
{
	long	sign;
	long	num;

	num = 0;
	sign = 1 + ((**str == '-') * -2);
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str != '\0' && ('0' <= **str && **str <= '9') && **str != ' ')
	{
		num = num * 10 + (**str - '0');
		(*str)++;
		if (((num > LONG_MAX / 10) && ft_isdigit(**str) == 1) || \
			((num == LONG_MAX / 10) && **str > (LONG_MAX % 10) + '0'))
			return (INT_MAX + 3L);
	}
	return (num * sign);
}

static int	chk_dub(long int *num, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (i != j && num[i] == num[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	create_chk_array(char **str, int count)
{
	long int	*num;
	int			i;

	i = 0;
	num = NULL;
	num = malloc(sizeof(int) * count);
	if (num == NULL)
		exit(1);
	while (**str != '\0')
	{
		while (**str == ' ')
			(*str)++;
		num[i] = string_atol(str);
		if (num[i] < INT_MIN || INT_MAX < num[i])
			return (0);
		i++;
	}
	if (chk_dub(num, count) == 0)
	{
		free(num);
		return (0);
	}
	free(num);
	return (1);
}

int	chk_num_string(char *str)
{
	size_t	i;
	size_t	count;
	char	*new_str;

	i = 0;
	count = 0;
	new_str = str;
	if (str[0] == '\0' || str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
			i++;
		if (!(ft_isdigit(str[i])) && str[i] != ' ')
			return (0);
		if (ft_isdigit(str[i]) && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
		i++;
	}
	if (create_chk_array(&new_str, count) == 0)
		return (0);
	return (1);
}
