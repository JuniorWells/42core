/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:56:00 by kchaniot          #+#    #+#             */
/*   Updated: 2021/12/16 16:56:01 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	match_them(t_object *mlx, char c, int *point)
{
	if (c == '1')
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/wall.xpm", \
		&((*mlx).img.wid), &((*mlx).img.height));
	else if (c == 'P')
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/ply_r.xpm", \
		&((*mlx).img.wid), &((*mlx).img.height));
	else if (c == 'C')
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/gold.xpm", \
		&((*mlx).img.wid), &((*mlx).img.height));
	else if (c == 'E')
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/exit.xpm", \
		&((*mlx).img.wid), &((*mlx).img.height));
	else
		(*mlx).img.img = mlx_xpm_file_to_image((*mlx).mlx, "./img/floor.xpm", \
		&((*mlx).img.wid), &((*mlx).img.height));
	mlx_put_image_to_window((*mlx).mlx, (*mlx).win, (*mlx).img.img, \
	point[0], point[1]);
	mlx_destroy_image((*mlx).mlx, (*mlx).img.img);
}

void	create_map(t_object *mlx, t_list *map)
{
	int		point[2];
	int		i;
	char	*line;
	t_list	*temp;

	i = 0;
	temp = map;
	point[0] = 0;
	point[1] = 0;
	while (temp)
	{
		line = temp->content;
		while (line[i] && line[i] != '\n')
		{
			match_them(mlx, line[i], point);
			i++;
			point[0] += 32;
		}
		temp = temp->next;
		point[1] += 32;
		point[0] = 0;
		i = 0;
	}
}
