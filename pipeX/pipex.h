/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:59:09 by kchaniot          #+#    #+#             */
/*   Updated: 2021/10/26 15:32:38 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define PATH "PATH="
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_command
{
	char				**cmd_args;
	char				*path;
	struct s_command	*prev;
	struct s_command	*next;
}	t_command;

int			get_input_fd(char *file);
int			get_output_fd(char *file);
char		*get_path(char *cmd_name, char **env);
void		input_error(void);
void		exec_error(t_command *cmd);
void		piping(t_command *cmd, char **env);
void		ft_lst_add_back(t_command **lst, t_command *new);
t_command	*populate(t_command *cmd, char *s, char **env);
t_command	**create_list(int elem, char **argv, char **env, t_command **lst);

#endif