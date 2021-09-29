/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:33:00 by kchaniot          #+#    #+#             */
/*   Updated: 2021/09/27 20:00:57 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	while ((9 <= (*str) && (*str) <= 13) || (*str == ' '))
		str++;
	if ((*str) == '+' || (*str) == '-')
	{
		if (*(str++) == '-')
			sign *= -1;
	}
	while (*str >= 48 && *str <= 57)
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	return (res * sign);
}
