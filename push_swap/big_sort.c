/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:12:08 by kchaniot          #+#    #+#             */
/*   Updated: 2021/09/29 17:20:27 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(int *arr_a, int len_a)
{
	int	*arr_b;
	int	max_index;
	int	max_bits;

	max_bits = 0;
	arr_b = (int *)malloc(len_a * sizeof(int));
	max_index = len_a - 1;
	while (max_index >> max_bits)
		++max_bits;
	the_final_sort(arr_a, arr_b, len_a, max_bits);
	free(arr_b);
}

void	the_final_sort(int *stack_a, int *stack_b, int len_a, int max_bits)
{
	int	i;
	int	j;
	int	size;
	int	len_b;

	size = len_a;
	len_b = 0;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a >> i) & 1) == 1)
				rotate_a(stack_a, len_a);
			else
				push_b(stack_b, stack_a, &len_b, &len_a);
			++j;
		}
		while (len_b > 0)
			push_a(stack_a, stack_b, &len_a, &len_b);
		i++;
	}
}
