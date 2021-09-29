/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:59:33 by kchaniot          #+#    #+#             */
/*   Updated: 2021/09/29 14:43:45 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int *arr, int len)
{
	int	temp;
	int	i;

	i = 0;
	temp = arr[0];
	while (i < len - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[len - 1] = temp;
	write(1, "ra\n", 3);
}

void	rotate_b(int *arr, int len)
{
	int	temp;
	int	i;

	i = 0;
	temp = arr[0];
	while (i < len - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[len - 1] = temp;
	write(1, "rb\n", 3);
}

void	rotate_both(int *arr1, int *arr2, int len1, int len2)
{
	int	temp1;
	int	temp2;
	int	i;
	int	j;

	i = 0;
	temp1 = *arr1;
	while (i < len1 - 1)
	{
		arr1[i] = arr1[i + 1];
		i++;
	}
	arr1[len1 - 1] = temp1;
	j = 0;
	temp2 = *arr2;
	while (j < len2 - 1)
	{
		arr2[j] = arr2[j + 1];
		i++;
	}
	arr2[len2 - 1] = temp2;
	write(1, "rr\n", 3);
}

int	is_sorted(int *arr, int len)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}
