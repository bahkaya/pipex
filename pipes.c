/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:02:44 by bahkaya           #+#    #+#             */
/*   Updated: 2025/09/04 15:10:24 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_first_pipe(int *fd, int infile)
{
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
}

void	ft_middle_pipe(int temp, int *fd)
{
	dup2(temp, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
}

void	ft_last_pipe(int temp, int outfile, int *fd)
{
	close(fd[1]);
	dup2(temp, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
}

void	ft_function(int i, int *fd, char **envp, char const **av)
{
	int					k;
	struct pipes_func	ft;

	ft.infile = open(av[1], O_RDONLY, 0644);
	k = 0;
	while (av[k] != NULL)
		k++;
	ft.outfile = open(av[k - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (i == 2)
		ft_first_pipe(fd, ft.infile);
	if (i != 2 && i != k - 2)
		ft_middle_pipe(ft.temp, fd);
	if (i == k - 2)
		ft_last_pipe(ft.temp, ft.outfile, fd);
	if (access(av[i], F_OK | X_OK) == 0)
	{
		ft.execute = ft_split(av[i], ' ');
		execve(av[i], ft.execute, envp);
	}
	ft.path = ft_command_location(av[i], envp);
	ft.execute = ft_split(av[i], ' ');
	execve(ft.path, ft.execute, envp);
	exit(EXIT_SUCCESS);
}

void	ft_pipe_exc(char const **av, char **envp, int ac)
{
	int					i;
	struct pipes_func	ft;

	i = 2;
	while (i < ac -1)
	{
		pipe(ft.fd);
		ft.id = fork();
		if (ft.id == 0)
		{
			ft_function(i, ft.fd, envp, av);
			wait(&ft.id);
		}
		close(ft.fd[1]);
		ft.temp = ft.fd[0];
		i++;
	}
}
