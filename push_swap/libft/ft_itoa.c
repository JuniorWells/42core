/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:11:59 by kchaniot          #+#    #+#             */
/*   Updated: 2021/05/26 18:21:06 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(long int n)
{
	int	length;

	if (n < 0)
		n = -n;
	length = 1;
	while (n > 9)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char	*ft_create(long int n, int neg, int len, char *s)
{
	if (n == 0)
	{
		*s = '0';
		return (s);
	}
	if (neg)
	{
		s[0] = '-';
		n = -n;
		len++;
	}
	s[len] = 0;
	while (n > 0)
	{
		len--;
		s[len] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int num)
{
	int		length;
	int		is_neg;
	char	*ret;
	long	n;

	n = num;
	length = ft_getlen(n);
	if (n < 0)
	{
		is_neg = 1;
		ret = (char *)malloc((length + 2) * sizeof(char));
		if (!ret)
			return (NULL);
		ret = ft_create(n, is_neg, length, ret);
		return (ret);
	}
	else
	{
		is_neg = 0;
		ret = (char *)malloc((length + 1) * sizeof(char));
		if (!ret)
			return (NULL);
		ret = ft_create(n, is_neg, length, ret);
		return (ret);
	}
}
