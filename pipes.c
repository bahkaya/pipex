/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:02:44 by bahkaya           #+#    #+#             */
/*   Updated: 2025/09/04 18:35:53 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_first_pipe(int *fd, int infile)
{
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
}

void	ft_last_pipe(int outfile, int *fd)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
}
void	ft_execute(int i, char const **av, char **envp)
{
	char *path;
	char **execute_comm;
	path = ft_command_location(av[i], envp);
	execute_comm = ft_split(av[i], ' ');
	execve(path, execute_comm, envp);
}

void	ft_pipe_exc(char const **av, char **envp, int ac)
{
	int		i;
	int		id;
	int		fd[2];
	int		infile;
	int		outfile;
	infile = open(av[1], O_RDONLY, 0644);
	outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if(infile < 0 || outfile < 0)
		exit (EXIT_FAILURE);
	i = 2;
	while (i < ac -1)
	{
		pipe(fd);
		id = fork();
		if (id == 0)
		{
			if (i != ac - 2)
				ft_first_pipe(fd, infile);
			if (i == ac - 2)
				ft_last_pipe(outfile, fd);
			ft_execute(i, av, envp);
		}
		i++;
	}
}
