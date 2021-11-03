/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 01:00:18 by kchaniot          #+#    #+#             */
/*   Updated: 2021/11/03 10:02:56 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	append_out(char *file, char *path)
{
	int	fd_out;

	fd_out = 1;
	if (!access(path, F_OK))
	{
		fd_out = open(file, O_RDWR | O_CREAT | O_APPEND, 0777);
		if (fd_out < 0)
		{
			write(STDERR_FILENO, "File read failed\n", 18);
			write(STDERR_FILENO, "Maybe check permissions\n", 25);
			exit(2);
		}
	}
	return (fd_out);
}

char	*get_pwd_path(char **env)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (!ft_strncmp(env[i], PWD, ft_strlen(PWD)))
		{
			path = ft_strjoin(ft_strchr(env[i], '/'), "/");
			return (path);
		}
		env++;
	}
	return (path);
}

void	extra(char *limiter)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	line = "mykonos";
	pipe(fd);
	pipe_error_check(pipe(fd));
	pid = fork();
	pid_error_check(pid);
	if (!pid)
		child_extra(fd, line, limiter);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
		close(fd[0]);
	}
}

void	child_extra(int *fd, char *line, char *limiter)
{
	close(fd[0]);
	while (*line)
	{
		line = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(line, limiter, ft_strlen(limiter)))
			exit(EXIT_SUCCESS);
		write(fd[1], line, ft_strlen(line));
	}
	close(fd[1]);
}
