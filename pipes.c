/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:02:44 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/27 13:20:23 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
void	ft_pipe_exc(char const **av, char **envp, int ac, int infile, int outfile, int i)
{
	int fd[2];
	int id;
	int temp;
	temp = 0;
	// second pipe doesn't get connected with previous pipe
	// loop over commands
		char	*path;
		char	**execute;

		pipe(fd);
		id = fork();
		if (id == 0)
		{
			if (i == 2)
			{
				close(fd[0]);
				dup2(infile, STDIN_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				close (infile);
			}
		//	if (i != 2 || i != ac - 2)
		//	{
		//		close (fd[1]);
		//		dup2(fd[0], STDIN_FILENO);
		//		close (fd[0]);
		//	}
			if (i == ac - 2)
			{
				close (fd[1]);
				dup2(fd[0], STDIN_FILENO);
				dup2(outfile, STDOUT_FILENO);
				close(fd[0]);
				close(outfile);
			}
			close(fd[1]);
			temp = fd[0];
			path = ft_command_location(av[i], envp);
			execute = ft_split(av[i], ' ');
			execve(path, execute, envp);
		}
		else if (id != 0)
		{
			close(fd[0]);
			close(fd[1]);
			close (infile);
			close (outfile);
		}
}
