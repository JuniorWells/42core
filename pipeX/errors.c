/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:50:00 by kchaniot          #+#    #+#             */
/*   Updated: 2021/10/31 20:03:14 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	input_error(void)
{
	write(STDERR_FILENO, "usage: ./pipex infile \"cmd1\" \"cmd2\" ... \
\"cmdn\" outfile\n", 56);
	write(STDERR_FILENO, "Better luck next time :)\n", 26);
	exit(-1);
}

void	exec_error(t_command *cmd)
{
	write(STDERR_FILENO, *(cmd->cmd_args), ft_strlen(*(cmd->cmd_args)));
	write(STDERR_FILENO, ": command not found\n", 21);
	write(STDERR_FILENO, "What are you trying to do there mate?\n", 39);
	exit(127);
}

void	pipe_error_check(int p_fd)
{
	if (p_fd < 0)
	{
		perror("pipe");
		exit(-1);
	}
}

void	pid_error_check(int pid)
{
	if (pid < 0)
	{
		perror("fork");
		exit(-1);
	}
}

void	error_here_doc(void)
{
	write(STDERR_FILENO, "usage: ./pipex here_doc LIMITER \"cmd1\" \"cmd2\" \
outfile\n", 55);
	write(STDERR_FILENO, "RTFM :)\n", 9);
	exit(-1);
}
