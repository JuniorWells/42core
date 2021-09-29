/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:33:25 by kchaniot          #+#    #+#             */
/*   Updated: 2021/09/29 15:09:51 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(int *arr, int len)
{
	if (!is_sorted(arr, len))
		swap_a(arr);
	else
		exit(-1);
}

void	sort_3(int *arr, int len)
{
	if (arr[0] > arr[1] && arr[1] > arr[2])
	{
		rotate_a(arr, len);
		swap_a(arr);
	}
	else if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] < arr[2])
		rotate_a(arr, len);
	else if (arr[0] > arr[1] && arr[0] < arr[2])
		swap_a(arr);
	else if (arr[0] < arr[1] && arr[0] > arr[2])
		rev_rotate_a(arr, len);
	else if (arr[0] < arr[2] && arr[1] > arr[2])
	{
		rotate_a(arr, len);
		swap_a(arr);
		rev_rotate_a(arr, len);
	}
	else
		exit(-1);
}

void	sort_4(int *arr, int len)
{
	int	min;
	int	*arr2;
	int	len2;

	arr2 = (int *)malloc(sizeof(int));
	if (!arr2)
		return ;
	len2 = 0;
	min = find_min(arr, len);
	while (*arr != min)
		rotate_a(arr, len);
	push_b(arr2, arr, &len2, &len);
	sort_3(arr, len);
	push_a(arr, arr2, &len, &len2);
	free(arr2);
}

void	sort_5(int *arr, int len)
{
	int	min;
	int	*arr2;
	int	len2;

	arr2 = (int *)malloc(sizeof(int));
	if (!arr2)
		return ;
	len2 = 0;
	min = find_min(arr, len);
	while (*arr != min)
		rotate_a(arr, len);
	push_b(arr2, arr, &len2, &len);
	sort_4(arr, len);
	push_a(arr, arr2, &len, &len2);
	while (len--)
		printf("%d ", *arr++);
	free(arr2);
}
