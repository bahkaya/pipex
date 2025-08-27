#include "ft_pipex.h"
int main(int ac, char **av, char **envp)
{
	int i;
	i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
		/*while (i < ac - 2)
		{
			path = ft_command_location(av[i], envp);
			execute = ft_split (av[i], ' ');
					printf("%s\n%s\n%s\n", "after parse ", path, execute[i]);
			id = fork();
			if (id == 0 && i == 2)
			{
				ft_first_pipe(path, execute, av[1], envp, fd);
				printf("%s\n", "while loop in child ");
			}
			else if (id != 0 && i == ac - 1)
			{
				id = fork();
				ft_last_pipe(path, execute, av[4], envp, fd);
						printf("%s\n", "while loop in child ");
			}
			i++;
		}*/

// 1 - 3 tane fonksiyon gerekli
// 1- first pipe that reads from the file
// 2- second and so forth for the exc commands that takes from the other pipes' input
// 3- last pipe that takes the input and write to the out file 
// In conclusion the pipex will accomplished with bonus 
// Solely the heredoc will be left.
/*int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int infile = open(av[1], O_RDONLY, 0666);
		dup2(infile , STDIN_FILENO);
		dup2(fd[1] , STDOUT_FILENO);
		close(infile);
		close(fd[1]);
		execve(command, execute, envp);
	}

	if (id != 0)
	{
		id2 = fork();
	}
	if (id2 == 0)
	{
		close(fd[1]);
		int file = open(av[4], O_CREAT | O_WRONLY | O_TRUNC , 0666);
		dup2(fd[0] , STDIN_FILENO);
		dup2(file , STDOUT_FILENO);
		close(fd[0]);
		close(file);
		execve(command_2, execute_2, envp);
	}
}*/

// void	command_to_execute(int *fd, const char *av, char **execute, char *command)
// {
// 	close(fd[0]);
// 	int infile = open(av, O_RDONLY, 0666);
// 	dup2(infile , STDIN_FILENO);
// 	dup2(fd[1] , STDOUT_FILENO);
// 	close(infile);
// 	close(fd[1]);
// 	execve(command, execute, NULL);
// }
// int main(int ac, char const *av[])
// {
// 	int fd[2];
// 	char *command;
// 	char **execute;
// 	int id2;
// 	char *command_2;
// 	char **execute_2;
// 
// 	command = ft_command_location(av[2]);
// 	execute = ft_split(av[2], ' ');
// 	command_2 = ft_command_location(av[3]);
// 	execute_2 = ft_split(av[3], ' ');
// 	if (pipe(fd) == -1)
// 	{
// 		return (1);
// 	}
// 	int id = fork();
// 	if (id == 0)
// 	{
// 		command_to_execute(fd, av[1], execute, command);
// 	}
// 	if (id != 0)
// 	{
// 		id2 = fork();
// 	}
// 	if (id2 == 0)
// 	{
// 		command_to_execute(fd, av[4], execute_2, command);
// 	}
// 	{
// 		
// 		int i;
// 	
// 		i = 0;
// 		while(execute[i] != NULL || execute_2[i] != NULL)
// 		{
// 			free(execute[i]);
// 			free(execute_2[i]);
// 			i++;
// 		}
// 		free(execute);
// 		free(execute_2);
// 		free(command);
// 		free(command_2);
// 		close(fd[0]);
// 		close(fd[1]);
// 	}
// 	return 0;
// }