/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:16:57 by kchaniot          #+#    #+#             */
/*   Updated: 2021/12/15 16:19:37 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	please_exit(t_object *mlx)
{
	if ((*mlx).map)
		ft_lstclear(&mlx->map, free);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	key_hook(int key, t_object *mlx)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	{
		position(mlx, key);
		create_map(mlx, (*mlx).map);
	}
	if (key == ESC)
		please_exit(mlx);
	return (0);
}

int	render(t_object *mlx)
{
	char	*moves;
	size_t	len;

	len = length_without_n((*mlx).map->content) * 32;
	moves = ft_itoa((*mlx).moves);
	mlx_string_put((*mlx).mlx, (*mlx).win, len - 30, 20, 0xFFFFFF, moves);
	free(moves);
	return (0);
}

int	is_it_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (!ft_strncmp(str + (len - 4), ".ber\0", 5))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_object	mlx;
	int			fd_map;

	if (argc != 2 || !is_it_ber(argv[1]))
		exit_args();
	fd_map = open(argv[1], O_RDONLY);
	if (fd_map <= 0)
		exit_file();
	if (error_in_map(&(mlx.map), fd_map))
	{
		ft_lstclear(&mlx.map, free);
		printf("Error\n");
		return (2);
	}
	close(fd_map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, length_without_n(mlx.map->content) * 32, \
	ft_lstsize(mlx.map) * 32, "so_long");
	create_map(&mlx, mlx.map);
	mlx_key_hook(mlx.win, key_hook, (void *) &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, please_exit, &mlx);
	mlx_loop_hook(mlx.mlx, render, (void *) &mlx);
	mlx_loop(mlx.mlx);
}
