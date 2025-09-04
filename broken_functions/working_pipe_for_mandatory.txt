#include "ft_pipex.h"
void	ft_pipe_exc(char const **av, char **envp, int ac, int infile, int outfile)
{
	int fd[2];
	int temp;
	int id;
	int i;
	i = 2;
	// second pipe doesn't get connected with previous pipe
	// loop over commands
		char	*path;
		char	**execute;
		pipe(fd);
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		temp = fd[0];
		while (i < ac - 1)
		{
			id = fork();
			if (id == 0)
			{
				if (i == 2)
				{
					close(fd[0]);
					dup2(infile, STDIN_FILENO);
					dup2(fd[1], STDOUT_FILENO);
					
				}
				if (i != 2 && i != ac - 2)
				{
					dup2(temp , STDOUT_FILENO);
					dup2(fd[1], STDOUT_FILENO);
					temp = fd[0];
				}
				if (i == ac - 2)
				{
					dup2(temp, fd[1]);
					dup2(outfile, STDOUT_FILENO);
				}
				path = ft_command_location(av[i], envp);
				execute = ft_split(av[i], ' ');
				execve(path, execute, envp);
				exit(EXIT_SUCCESS);
			}
		i++;
	}
}