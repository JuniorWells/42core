/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_and_pushes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:08:15 by kchaniot          #+#    #+#             */
/*   Updated: 2021/09/28 23:04:36 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *arr)
{
	int	temp;

	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	write(1, "sa\n", 3);
}

void	swap_b(int *arr)
{
	int	temp;

	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	write(1, "sb\n", 3);
}

void	swap_both(int *arr1, int *arr2)
{
	int	temp1;
	int	temp2;

	temp1 = arr1[0];
	arr1[0] = arr1[1];
	arr1[1] = temp1;
	temp2 = arr2[0];
	arr2[0] = arr2[1];
	arr2[1] = temp2;
	write(1, "ss\n", 3);
}

void	push_a(int *dest, int *src, int *len_dest, int *len_src)
{
	int	i;
	int len;

	i = 0;
	len = *len_dest;
	while (len > 0)
	{
		dest[len] = dest[len - 1];
		len--;
	}
	*dest = *src;
	while (i < *len_src)
	{
		src[i] = src[i + 1];
		i++;
	}
	*len_src -= 1;
	*len_dest += 1;
	write(1, "pa\n", 3);
}

void	push_b(int *dest, int *src, int *len_dest, int *len_src)
{
	int	i;
	int len;

	i = 0;
	len = *len_dest;
	while (len > 0)
	{
		dest[len] = dest[len - 1];
		len--;
	}
	*dest = *src;
	while (i < *len_src)
	{
		src[i] = src[i + 1];
		i++;
	}
	*len_src -= 1;
	*len_dest += 1;
	write(1, "pb\n", 3);
}
