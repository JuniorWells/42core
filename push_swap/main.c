/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:33:19 by kchaniot          #+#    #+#             */
/*   Updated: 2021/09/28 23:16:52 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*input;
	int	*sorted;
	int *stack_a;
	//int i;
	int length;
	
	//if (error_there(argc, argv))
	//	write(1, "Error\n", 6);
	//else
	//{
		length = argc - 1;
		input = pass_arguments(argc, argv);
		 // fix length // 
		if (is_sorted(input, length))
			exit(-1);
		sorted = initial_sort(input, length);
		stack_a = transmute(input, sorted, length);
		//for (i = 0; i < argc - 1; i++)
		//	printf("%d ", input[i]);
		//for (i = 0; i < argc - 1; i++)
		//	printf("%d ", sorted[i]);
		//printf("\n%d\n", length);
		//for (i = 0; i < argc - 1; i++)
		//	printf("%d ", stack_a[i]);
		free(input);
		free(sorted);
		if (length == 2)
			sort_2(stack_a, length);
		else if (length == 3)
			sort_3(stack_a, length);
		else
			sort_big(stack_a, length);
		//else if (length == 4)
		//	sort_4;
		//else
		//	big_sort;
	//}
	return (0);
}
