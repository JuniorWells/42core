/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:33:19 by kchaniot          #+#    #+#             */
/*   Updated: 2021/10/02 23:23:30 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*input;
	int	length;

	if ((argc == 2 && (!ft_strchr(argv[1], ' '))) || argc <= 1)
		exit(-1);
	if (argc == 2 && (ft_strchr(argv[1], ' ')))
	{
		input = handle_input_variable(argv, &length);
		error_here(length, input);
	}
	else
	{
		if (error_there(argc, argv))
		{
			write(1, "Error\n", 6);
			exit(-1);
		}
		input = pass_arguments(argc, argv);
		length = argc - 1;
	}	
	implement(input, length);
	free(input);
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

void	implement(int *input, int length)
{
	int *sorted;
	int *stack_a;
	
	if (is_sorted(input, length))
	{
		free(input);
		exit(-1);
	}
	sorted = initial_sort(input, length);
	stack_a = transmute(input, sorted, length);
	choices(stack_a, length);
	free(sorted);
	free(stack_a);
}

void	free_and_out(int len, char **s)
{
	while (len-- >=0)
		free(s[len]);
	free(s);
	write(1, "Error\n", 6);
	exit(-1);
}
