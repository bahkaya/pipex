/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:56:54 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/23 16:08:19 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

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
int main(int ac, char const *av[], char **envp)
{
	int fd[2];
	char *command;
	char **execute;
	char *command_2;
	char **execute_2;
	int id2;
	command = ft_command_location(av[2], envp);
	command_2 = ft_command_location(av[3], envp);
	execute = ft_split(av[2], ' ');
	execute_2 = ft_split(av[3], ' ');
	/*while (ac >= 1)
	{
		ft_exc_and_write()
	}*/
		
	if (pipe(fd) == -1)
	{
		return (1);
	}
	
	{
		
		int i;
	
		i = 0;
		while(execute[i] != NULL || execute_2[i] != NULL)
		{
			free(execute[i]);
			free(execute_2[i]);
			i++;
		}
		free(execute);
		free(execute_2);
		free(command);
		free(command_2);
		close(fd[0]);
		close(fd[1]);
	}
	return 0;
}
