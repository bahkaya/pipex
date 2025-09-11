/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:02:44 by bahkaya           #+#    #+#             */
/*   Updated: 2025/09/11 17:29:52 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_first_pipe(int *fd, int infile)
{
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(infile);
}

static void	ft_last_pipe(int outfile, int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(outfile);
}
void	ft_execute(char const **av, char **envp, int i)
{
	char *path;
	char **execute;
	path = ft_command_location(av[i], envp);
	execute = ft_split(av[i], ' ');
	execve(path, execute, envp);
}
void	ft_pipe_exc(char const **av, char **envp, int ac, int infile)
{
	int		i;
	int		id1;
	int		id2;
	int		status;
	int		fd[2];
	int		outfile;
	outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if(infile < 0 || outfile < 0)
		exit (EXIT_FAILURE);
	i = 2;
	pipe(fd);
	id1 = fork();
	if (id1 == 0)
	{
		ft_first_pipe(fd, infile);
		ft_execute(av, envp, i);
	}
	id2 = fork();
	if (id2 == 0)
	{
		ft_last_pipe(outfile, fd);
		ft_execute(av, envp, ac - 2);
	}
		close (fd[1]);
		close (fd[0]);
}
