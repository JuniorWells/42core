#include "pipex.h"


int	main(int argc, char *argv[])
{
	t_command *cmd1;
	t_command *cmd2;

	if (argc != 5)
		write(STDOUT_FILENO, "Error\n", 6);
	else
	{
		cmd1 = malloc(sizeof(t_command));
		cmd2 = malloc(sizeof(t_command));
		populate(cmd1, argv[2], argv[1], "1");
		populate(cmd2, argv[3], "0", argv[4]);
		create_process(cmd1, cmd2);
	}
	printf("mykonos\n");
	return (0);	
}

void	create_process(t_command *cmd1, t_command *cmd2)
{
	int	child_process;
	int	fd[2];

	if (pipe(fd) == -1)
		return ;
	child_process = fork();
	if (!child_process)
	{
		dup2(cmd1->fd_input, 0);
		dup2(fd[1], 1);
		execve(cmd1->path, cmd1->cmd_args, NULL);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(cmd2->fd_output, 1);
		wait(NULL);
		execve(cmd2->path, cmd2->cmd_args, NULL);
		close(fd[0]);
	}
	close(fd[0]);
	close(fd[1]);
}

void	populate(t_command *cmd, char *cmd_name, char *infile, char *outfile)
{	
	cmd->cmd_args = ft_split(cmd_name, ' ');
	cmd->path = get_path(*cmd->cmd_args);
	cmd->fd_input = find_input_fd(infile);
	cmd->fd_output = find_output_fd(outfile);
}
