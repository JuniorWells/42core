/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:59:09 by kchaniot          #+#    #+#             */
/*   Updated: 2021/11/03 10:41:08 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define PATH "PATH="
# define PWD "PWD="
# define HERE_DOC "here_doc"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "libft/libft.h"
# include <stdio.h>
# include <errno.h>

typedef struct s_command
{
	char				**cmd_args;
	char				*path;
	struct s_command	*prev;
	struct s_command	*next;
}	t_command;

int			get_input_fd(char *file);
int			get_output_fd(char *file);
int			get_heredoc_fd(char *file, char *path);
int			append_out(char *file, char *path);
char		*get_path(char *cmd_name, char **env);
char		*get_pwd_path(char **env);
char		*check_path(char **poss_paths, char *cmd, char *path);
void		input_error(void);
void		extra(char *limiter);
void		pipe_error_check(int p_fd);
void		pid_error_check(int pid);
void		error_here_doc(void);
void		child_extra(int *fd, char *line, char *limiter);
void		piping(t_command *cmd, char **env);
void		ft_lst_add_back(t_command **lst, t_command *new);
void		normality(int argc, char **argv, char **env);
void		limiter_case(int argc, char **argv, char **env);
t_command	*populate(t_command *cmd, char *s, char **env);
t_command	**create_list(int elem, char **argv, char **env, t_command **lst);

#endif