/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:42:20 by kchaniot          #+#    #+#             */
/*   Updated: 2021/10/31 20:01:45 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_input_fd(char *file)
{
	int	fd_in;

	fd_in = STDIN_FILENO;
	if (!access(file, F_OK))
		fd_in = open(file, O_RDONLY, 0777);
	else
	{
		write(STDERR_FILENO, file, ft_strlen(file));
		write(STDERR_FILENO, ": No such file or directory\n", 29);
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
	if (fd_out == -1)
	{
		write(STDERR_FILENO, "No such file or no permission\n", 31);
		exit(2);
	}
	return (fd_out);
}

char	*get_path(char *cmd_name, char **env)
{
	char	*cmd;
	char	*path;
	char	**poss_paths;
	int		i;

	i = 0;
	cmd = ft_strjoin("/", cmd_name);
	while (env[i])
	{
		if (!ft_strncmp(env[i], PATH, ft_strlen(PATH)))
			path = ft_strchr(env[i], '/');
		i++;
	}
	poss_paths = ft_split(path, ':');
	while (*poss_paths)
	{
		path = ft_strjoin(*poss_paths, cmd);
		if (!access(path, F_OK) && !access(path, X_OK))
			break ;
		else
			free(path);
		poss_paths++;
	}
	free(cmd);
	return (path);
}
