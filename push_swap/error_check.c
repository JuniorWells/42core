/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:31:41 by kchaniot          #+#    #+#             */
/*   Updated: 2021/09/28 23:16:41 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc;
	while (--i > 0 )
	{
		j = i - 1;
		while (j >= 0)
		{
			if (!ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])))
				return (1);
			j--;
		}
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
	if (argc < 3)
		return (1);
	else if (has_duplicates(argc, argv))
		return (1);
	else if (more_than_int(argc, argv))
		return (1);
	else if (more_than_digits(argc, argv))
		return (1);
	return (0);
}
