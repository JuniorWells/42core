/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:50:00 by kchaniot          #+#    #+#             */
/*   Updated: 2021/11/03 10:43:27 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	input_error(void)
{
	write(STDERR_FILENO, "usage: ./pipex infile \"cmd1\" \"cmd2\" ... \
\"cmdn\" outfile\n", 56);
	write(STDERR_FILENO, "Better luck next time :)\n", 26);
	exit(EXIT_FAILURE);
}

void	pipe_error_check(int p_fd)
{
	if (p_fd < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	pid_error_check(int pid)
{
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

void	error_here_doc(void)
{
	write(STDERR_FILENO, "usage: ./pipex here_doc LIMITER \"cmd1\" \"cmd2\" \
outfile\n", 55);
	write(STDERR_FILENO, "RTFM :)\n", 9);
	exit(EXIT_FAILURE);
}
