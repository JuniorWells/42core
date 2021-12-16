/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:32:54 by kchaniot          #+#    #+#             */
/*   Updated: 2021/12/15 16:19:58 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# define STDOUT 1
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

typedef struct s_image {
	void	*img;
	int		wid;
	int		height;
}				t_image;

typedef struct s_object {
	void	*mlx;
	void	*win;
	t_list	*map;
	t_image	img;
	int		moves;
	int		gold;
}				t_object;

size_t	length_without_n(char *s);
int		error_top_bot(char *line);
int		error_in_mid(char *line, int *misc);
int		error_in_map(t_list **map, int fd);
int		error_in_lines(t_list **map, int counter, size_t len, int *misc);

int		render(t_object *mlx);
void	create_map(t_object *mlx, t_list *map);
void	match_them(t_object *mlx, char c, int *point);
void	position(t_object *mlx, int key);
char	*find_next(t_list *line, int pos, int key);
t_list	*find_pos(t_list *map, int	*pos);

void	exit_args(void);
void	exit_file(void);
int		please_exit(t_object *mlx);

#endif