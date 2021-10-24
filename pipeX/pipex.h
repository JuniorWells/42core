#ifndef PIPEX_H
# define PIPEX_H

# define BIN_FOLDERS 5

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "libft/libft.h"

typedef struct s_command
{
	char	**cmd_args;
	char	*path;
	int		fd_input;
	int		fd_output;
}	t_command;

int		find_input_fd(char *file);
int		find_output_fd(char *file);
char	*get_path(char *cmd_name);
void	populate(t_command *cmd, char *cmd_name, char *infile, char *outfile);
void	create_process(t_command *cmd1, t_command *cmd2);

#endif