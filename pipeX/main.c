/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:26:50 by kchaniot          #+#    #+#             */
/*   Updated: 2021/11/03 10:43:32 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (argc < 5)
		input_error();
	if (!ft_strncmp(argv[1], HERE_DOC, ft_strlen(HERE_DOC)))
	{
		if (argc >= 6)
			limiter_case(argc, argv, env);
		else
			error_here_doc();
	}
	else
		normality(argc, argv, env);
	return (2);
}

void	normality(int argc, char **argv, char **env)
{
	int			elements;
	int			ffds[2];
	t_command	**lst;

	elements = argc - 3;
	lst = malloc(sizeof(t_command *));
	if (!lst)
		return ;
	lst = create_list(elements, argv, env, lst);
	ffds[0] = get_input_fd(argv[1]);
	ffds[1] = get_output_fd(argv[argc - 1]);
	dup2(ffds[0], STDIN_FILENO);
	dup2(ffds[1], STDOUT_FILENO);
	piping(*lst, env);
	*lst = (*lst)->next;
	while ((*lst)->next)
	{
		piping(*lst, env);
		*lst = (*lst)->next;
	}
	execve((*lst)->path, (*lst)->cmd_args, env);
	exit(127);
}

void	limiter_case(int argc, char **argv, char **env)
{
	char		*limiter;
	int			fdf[2];
	char		*pwd;
	t_command	**lst;

	limiter = argv[2];
	pwd = get_pwd_path(env);
	lst = malloc(sizeof(t_command *));
	if (!lst)
		return ;
	lst = create_list(argc - 4, argv, env, lst);
	fdf[0] = STDIN_FILENO;
	fdf[1] = append_out(argv[argc - 1], pwd);
	dup2(fdf[1], STDOUT_FILENO);
	extra(limiter);
	piping(*lst, env);
	*lst = (*lst)->next;
	while ((*lst)->next)
	{
		piping(*lst, env);
		*lst = (*lst)->next;
	}
	execve((*lst)->path, (*lst)->cmd_args, env);
	exit(127);
}

void	piping(t_command *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	pipe_error_check(pipe(fd));
	pid = fork();
	pid_error_check(pid);
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(cmd->path, cmd->cmd_args, env);
		exit(127);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
		close(fd[0]);
	}
}
