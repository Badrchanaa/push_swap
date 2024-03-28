/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:49:05 by bchanaa           #+#    #+#             */
/*   Updated: 2024/03/28 00:50:50 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

long	ft_abs(int a)
{
	if (a < 0)
		return (-(long)a);
	return (a);
}
