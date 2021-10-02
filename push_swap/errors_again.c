/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_again.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 23:15:04 by kchaniot          #+#    #+#             */
/*   Updated: 2021/10/02 23:29:42 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_here(int len, int *input)
{
	if (has_double(len, input) || out_of_limits(len, input))
	{
		free(input);
		write(1, "Error\n", 6);
		exit(-1);
	}
}

int		has_double(int len, int *input)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (input[i] == input[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		out_of_limits(int len, int *input)
{
	int i;
	
	i = 0;
	while (i < len)
	{
		if (input[i] < INT_MIN || input[i] > INT_MAX)
			return (1);
		i++;
	}
		
	return (0);
}