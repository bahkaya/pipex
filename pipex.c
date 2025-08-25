/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:56:54 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/25 18:57:51 by bahkaya          ###   ########.fr       */
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
	int infile;
	int outfile;

	infile = open(av[1], O_RDONLY, 0644);
	outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if ((infile == -1 || outfile == -1))
		return (NULL);
	ft_pipe_exc(av, envp, ac, infile, outfile);
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