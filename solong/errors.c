/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:30:52 by kchaniot          #+#    #+#             */
/*   Updated: 2021/12/15 16:15:18 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_in_mid(char *line, int *misc)
{
	if (*line++ != '1')
		return (1);
	while (*line && *line != '\n')
	{
		if (*line == 'P')
			++misc[0];
		else if (*line == 'C')
			++misc[1];
		else if (*line == 'E')
			++misc[2];
		else if ((*line != '1') && (*line != '0'))
			return (1);
		line++;
	}
	if (*(line - 1) != '1')
		return (1);
	return (0);
}

size_t	length_without_n(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

int	error_top_bot(char *line)
{
	while (*line && (*line != '\n'))
		if (*line++ != '1')
			return (1);
	return (0);
}

int	error_in_map(t_list **map, int fd)
{
	char	*temp;
	int		counter;
	size_t	len;
	int		misc[3];

	counter = 0;
	while (counter < 3)
		misc[counter++] = 0;
	temp = get_next_line(fd);
	if (error_top_bot(temp))
		return (1);
	len = length_without_n(temp);
	counter = 0;
	while (temp)
	{
		++counter;
		ft_lstadd_back(map, ft_lstnew(temp));
		temp = get_next_line(fd);
	}
	if (error_in_lines(map, counter, len, misc))
		return (1);
	return (0);
}

int	error_in_lines(t_list **map, int counter, size_t len, int *misc)
{
	t_list	*obj;

	obj = (*map)->next;
	if (counter < 3)
		return (1);
	while (obj)
	{
		if (length_without_n(((char *)(obj)->content)) != len)
			return (1);
		if (--counter != 1)
		{
			if (error_in_mid(((char *)(obj)->content), misc))
				return (1);
		}
		else if (error_top_bot(((char *)(obj)->content)))
			return (1);
		obj = (obj)->next;
	}
	if (!misc[0] || !misc[1] || !misc[2])
		return (1);
	return (0);
}
