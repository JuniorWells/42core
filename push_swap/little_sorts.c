/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:33:25 by kchaniot          #+#    #+#             */
/*   Updated: 2021/09/28 23:37:22 by kchaniot         ###   ########.fr       */
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
	else if (arr[0] > arr[1] && arr[0] > arr[1] && arr[1] < arr[2])
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

void	sort_big(int *arr_a, int len_a)
{
	int	*arr_b;
	int	len_b;
	int	max_index;
	int	max_bits;
	
	//int i;
	
	len_b = 0;
	max_bits = 0;
	arr_b = (int *)malloc(len_a * sizeof(int));
	max_index = len_a - 1;
	while (max_index >> max_bits)
		++max_bits;
	//for (i = 0; i < len_a; i++)
	//	printf("%d ", arr_a[i]);
	//printf("\n");
	the_final_sort(arr_a, arr_b, len_a, len_b, max_bits);
	//printf("\n");
	//for (i = 0; i < len_a; i++)
	//	printf("%d ", arr_a[i]);

	free(arr_b);
	free(arr_a);
}

void	the_final_sort(int *stack_a, int *stack_b, int len_a, int len_b, int max_bits)
{
	int i;
	int j;
	int size;

	size = len_a;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a >> i)&1) == 1)
			{
				//printf("*stack_a: %d", *stack_a);
				//printf("*stack_b: %d\n", *stack_b);
				rotate_a(stack_a, len_a);
				//printf("RA:*stack_a: %d", *stack_a);
				//printf("*stack_b: %d\n\n", *stack_b);
			}
			else
			{
				//printf("*stack_a: %d", *stack_a);
				//printf("*stack_b: %d\n", *stack_b);
				push_b(stack_b, stack_a, &len_b, &len_a);
				//printf("PB:*stack_a: %d", *stack_a);
				//printf("*stack_b: %d\n\n", *stack_b);
			}
			//printf("lenb: %d, lena: %d, j: %d\n\n\n", len_b, len_a, j);
			++j;
		}
		while (len_b > 0)
		{
			//printf("*stack_a: %d", *stack_a);
			//printf("*stack_b: %d\n", *stack_b);
			push_a(stack_a, stack_b, &len_a, &len_b);
			//printf("PA:*stack_a: %d", *stack_a);
			//printf("*stack_b: %d\n\n", *stack_b);
		}
		i++;
	}
}
