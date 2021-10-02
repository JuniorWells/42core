/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:31:41 by kchaniot          #+#    #+#             */
/*   Updated: 2021/09/29 16:13:19 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	more_than_int(int argc, char **argv)
{
	while (--argc > 0)
		if (ft_atoi(argv[argc]) < INT_MIN || ft_atoi(argv[argc]) > INT_MAX)
			return (1);
	return (0);
}

int	more_than_digits(int argc, char **argv)
{
	int	i;

	while (--argc)
	{
		i = 0;
		while (argv[argc][i])
		{
			if (ft_isdigit(argv[argc][i]) || argv[argc][i] == '-' || \
				argv[argc][i] == '+')
				i++;
			else
				return (1);
		}
	}
	return (0);
}

int	error_there(int argc, char **argv)
{
	// if ((argc == 2 && !(ft_strchr(argv[1], ' '))) || argc <= 1)
	// 	exit(-1);
	if (has_duplicates(argc, argv))
		return (1);
	else if (more_than_int(argc, argv))
		return (1);
	else if (more_than_digits(argc, argv))
		return (1);
	return (0);
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
