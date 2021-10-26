/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:42:20 by kchaniot          #+#    #+#             */
/*   Updated: 2021/10/26 17:26:42 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_input_fd(char *file)
{
	int	fd_in;

	fd_in = STDIN_FILENO;
	if (!access(file, F_OK))
		fd_in = open(file, O_RDONLY);
	else
	{
		write(STDERR_FILENO, &file, ft_strlen(file));
		write(STDERR_FILENO, " No such file or directory\n", 28);
		exit(2);
	}
	if (fd_in < 0)
	{
		write(STDERR_FILENO, "Invalid read operation\n", 24);
		exit(2);
	}
	return (fd_in);
}

int	get_output_fd(char *file)
{
	int	fd_out;

	if (*file == '1')
	{
		fd_out = STDOUT_FILENO;
		return (fd_out);
	}
	fd_out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out < 0)
	{
		write(STDERR_FILENO, "Invalid read operation\n", 24);
		exit(2);
	}
	return (fd_out);
}

char	*get_path(char *cmd_name, char **env)
{
	char	*cmd;
	char	*path;
	char	**poss_paths;

	cmd = ft_strjoin("/", cmd_name);
	while (*env)
	{
		if (!ft_strncmp(*env, PATH, ft_strlen(PATH)))
			path = ft_strchr(*env, '/');
		env++;
	}
	poss_paths = ft_split(path, ':');
	while (*poss_paths)
	{
		path = ft_strjoin(*poss_paths, cmd);
		if (!access(path, F_OK && X_OK))
			break ;
		else
			free(path);
		poss_paths++;
	}
	free(cmd);
	return (path);
}

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
	write(STDERR_FILENO, "What are you trying there mate?\n", 33);
	exit(127);
}
