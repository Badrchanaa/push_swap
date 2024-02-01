/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:06:20 by bchanaa           #+#    #+#             */
/*   Updated: 2024/01/26 19:44:42 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

long	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	i = 0;
	res = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (res > ((res * 10) + str[i] - '0'))
			return ((long)INT_MAX + 1);
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res * sign);
}
