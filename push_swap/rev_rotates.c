/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:07:21 by kchaniot          #+#    #+#             */
/*   Updated: 2021/09/28 16:07:53 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(int *arr, int len)
{
	int	temp;
	int	i;

	i = --len;
	temp = arr[len];
	while (i)
	{
		arr[i] = arr[i - 1];
		--i;
	}
	arr[0] = temp;
	write(1, "rra\n", 4);
}

void	rev_rotate_b(int *arr, int len)
{
	int	temp;
	int	i;

	i = --len;
	temp = arr[len];
	while (i)
	{
		arr[i] = arr[i - 1];
		--i;
	}
	arr[0] = temp;
	write(1, "rrb\n", 4);
}

void	rev_rotate_both(int *arr1, int *arr2, int len1, int len2)
{
	int	temp1;
	int	temp2;
	int	i;
	int	j;

	i = --len1;
	temp1 = arr1[len1];
	while (i)
	{
		arr1[i] = arr1[i - 1];
		--i;
	}
	arr1[0] = temp1;
	j = --len2;
	temp2 = arr2[len2];
	while (j)
	{
		arr2[j] = arr2[j - 1];
		--j;
	}
	arr2[0] = temp2;
	write(1, "rrr\n", 4);
}
