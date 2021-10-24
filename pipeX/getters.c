#include "pipex.h"

int	find_input_fd(char *file)
{
	int fd_in;

	fd_in = STDIN_FILENO;
	if (*file == '0')
		return (fd_in);
	if (!access(file, F_OK))
		fd_in = open(file, O_RDONLY);
	if (fd_in < 0)
	{
		write(STDOUT_FILENO, "Invalid read operation\n", 24);
		exit(2);
	}
	return (fd_in);
}

int	find_output_fd(char *file)
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
		write(STDOUT_FILENO, "Invalid read operation\n", 24);
		exit(2);
	}
	if (ft_strchr(file, ' '))
		fd_out = 1;
	return (fd_out);
}

char	*get_path(char *cmd_name)
{
	char	*paths[BIN_FOLDERS] = { "/usr/bin/", "/bin/", "/usr/sbin/", "/sbin/", NULL };
	char	*correct_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		correct_path = ft_strjoin(paths[i], cmd_name);
		if (!access(correct_path, F_OK))
			return (correct_path);
		else
			free(correct_path);
		i++;
	}
	return (NULL);
}
