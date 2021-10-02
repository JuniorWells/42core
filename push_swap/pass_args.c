/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:58:06 by kchaniot          #+#    #+#             */
/*   Updated: 2021/10/02 23:00:35 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	little_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	*pass_arguments(int argc, char **argv)
{
	int		*initial_array;

	initial_array = (int *)malloc((argc - 1) * sizeof(int));
	if (!initial_array)
		return (0);
	while (--argc > 0)
		initial_array[argc - 1] = ft_atoi(argv[argc]);
	return (initial_array);
}

int	*initial_sort(int *array, int len)
{
	int	i;
	int	j;
	int	*new;
	int	length;

	length = len;
	new = (int *)malloc(len * sizeof(int));
	if (!new)
		return (0);
	while (--len >= 0)
		new[len] = array[len];
	i = 0;
	while (i < length - 1)
	{
		j = 0;
		while (j < (length - i - 1))
		{
			if (new[j] > new[j + 1])
				little_swap(&new[j], &new[j + 1]);
			++j;
		}
		++i;
	}
	return (new);
}

int	*transmute(int *unsorted, int *sorted, int len)
{
	int	*new;
	int	i;
	int	j;

	new = (int *)malloc(len * sizeof(int));
	if (!new)
		return (0);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (unsorted[i] == sorted[j])
				new[i] = j;
			j++;
		}
		++i;
	}
	return (new);
}

int		*handle_input_variable(char **argv, int *len)
{
	char	**temp;
	int		*input;
	int		i;

	temp = ft_split(argv[1], ' ');
	while (temp[*len])
		++(*len);
	input = malloc(*len * sizeof(int));
	if (!input)
		return (0);
	i = 0;
	while (i < *len)
	{
		if (!(error_there(*len, temp)))
			input[i] = ft_atoi(temp[i]);
		else
		{
			free(input);
			free_and_out(*len, temp);
		}
		i++;
	}
	free_and_in(*len, temp);
	return (input);
}