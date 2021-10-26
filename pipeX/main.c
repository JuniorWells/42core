/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:26:50 by kchaniot          #+#    #+#             */
/*   Updated: 2021/10/26 15:31:36 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int			elements;
	int			ffds[2];
	t_command	**lst;

	if (argc < 5)
		input_error();
	elements = argc - 3;
	lst = malloc(sizeof(t_command *));
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
	exec_error(*lst);
	return (1);
}

void	piping(t_command *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(cmd->path, cmd->cmd_args, env);
		exec_error(cmd);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}
