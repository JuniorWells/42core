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
	if (argc == 1 || (argc == 2 && !(ft_strchr(argv[1], ' '))))
		exit(-1);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		arguments_transform(argv);
	else
	{
		if (error_there(argc, argv))
		{
			write(1, "Error\n", 6);
			exit(-1);
		}
		implement(argc, argv);
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
