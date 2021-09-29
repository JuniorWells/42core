/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:33:19 by kchaniot          #+#    #+#             */
/*   Updated: 2021/09/29 18:11:42 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*input;
	int	*sorted;
	int	*stack_a;
	int	length;

	if (error_there(argc, argv))
		write(1, "Error\n", 6);
	else
	{
		length = argc - 1;
		input = pass_arguments(argc, argv);
		if (is_sorted(input, length))
		{
			free(input);
			exit(-1);
		}
		sorted = initial_sort(input, length);
		stack_a = transmute(input, sorted, length);
		choices(stack_a, length);
		free(input);
		free(sorted);
		free(stack_a);
	}
	return (0);
}

void	choices(int *stack_a, int length)
{
	if (length == 2)
		sort_2(stack_a, length);
	else if (length == 3)
		sort_3(stack_a, length);
	else if (length == 4)
		sort_4(stack_a, length);
	else if (length == 5)
		sort_5(stack_a, length);
	else
		sort_big(stack_a, length);
}

int	find_min(int *arr, int len)
{
	int	min;
	int	i;

	i = 0;
	min = arr[0];
	while (i < len)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}
