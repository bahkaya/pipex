/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_examples.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:56:54 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/18 14:49:13 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include <fcntl.h>

char	*ft_command_location(char const *av)
{

	char	*path;
	char	*path_location;
	char	*command;
	size_t i;
	i = 0;

	path = "/usr/bin/";
	while (av[i] != '\0' && av[i] != ' ')
		i++;
	command = ft_substr(av, 0, i);
	path_location = ft_strjoin(path, command);
	free (command);
	return (path_location);
}

int main(int ac, char const *av[])
{
	int fd[2];

	if (pipe(fd) == -1){
		return (1);
	}
	int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		char *command;
		char **execute;
		int infile = open(av[1], O_RDONLY, 0666);
		command = ft_command_location(av[2]);
		execute = ft_split(av[2], ' ');
		dup2(infile , STDIN_FILENO);
		dup2(fd[1] , STDOUT_FILENO);
		close(infile);
		close(fd[1]);
		execve(command, execute, NULL);
		free(command);
		free(execute);
	}
	if (id != 0)
		id = fork();
	if (id == 0)
	{
		close(fd[1]);
		char *command;
		char **execute;
		int file = open(av[4], O_CREAT | O_WRONLY | O_TRUNC , 0666);
		command = ft_command_location(av[3]);
		execute = ft_split(av[3], ' ');
		dup2(fd[0] , STDIN_FILENO);
		dup2(file , STDOUT_FILENO);
		close(fd[0]);
		close(file);
		execve(command, execute, NULL);
		free(command);
		free(execute);
	}
	return 0;
}
