/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:57:14 by kchaniot          #+#    #+#             */
/*   Updated: 2021/12/16 16:57:15 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*find_pos(t_list *map, int	*pos)
{
	t_list	*curr;

	curr = map->next;
	while (curr->next)
	{
		*pos = 0;
		while (*(char *)(curr->content + *pos) && (*(char *)(curr->content \
		+ *pos) != 'P') && (*(char *)(curr->content + *pos) != '\n'))
			*pos = *pos + 1;
		if (*(char *)(curr->content + *pos) == 'P')
			break ;
		map = curr;
		curr = curr->next;
	}
	return (map);
}

char	*find_next(t_list *line, int pos, int key)
{
	char	*ret;

	ret = (char *)(ft_lstlast(line)->content);
	if (key == UP)
		ret = (char *)(line->content + pos);
	else if (key == LEFT)
		ret = (char *)(line->next->content + pos - 1);
	else if (key == RIGHT)
		ret = (char *)(line->next->content + pos + 1);
	else if (key == DOWN)
		ret = (char *)(line->next->next->content + pos);
	return (ret);
}

void	position(t_object *mlx, int key)
{
	t_list	*line;
	int		pos;
	char	*curr;

	line = find_pos((*mlx).map, &pos);
	curr = find_next(line, pos, key);
	if (*curr != '1')
	{
		if (*curr == 'C')
			(*mlx).gold = (*mlx).gold + 1;
		else if (*curr == 'E' && ((*mlx).gold > 0))
			please_exit(mlx);
		else if (*curr == 'E')
			return ;
		*curr = 'P';
		*(char *)(line->next->content + pos) = '0';
		(*mlx).moves = (*mlx).moves + 1;
	}
	return ;
}
