/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:02:44 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/25 16:37:43 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
void	ft_first_pipe(char const **av, char **envp, int ac, int i)
{
	int fd[2];
	int id;
	int prev_fd;
while(i <= ac - 2)  // loop over commands
{
    pipe(fd);

    id = fork();
    if (id == 0) {
        if (i == 2) {
            // first command
            int infile = open(av[1], O_RDONLY);
            dup2(infile, STDIN_FILENO);
            close(infile);
        } else {
            // read from previous pipe
            dup2(prev_fd, STDIN_FILENO);
            close(prev_fd);
        }

        if (i == ac - 2) {
            // last command
            int outfile = open(av[ac-1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
            dup2(outfile, STDOUT_FILENO);
            close(outfile);
        } else {
            // middle command: write into current pipe
            dup2(fd[1], STDOUT_FILENO);
        }

        close(fd[0]); 
        close(fd[1]);

        char *path = ft_command_location(av[i], envp);
        char **execute = ft_split(av[i], ' ');
        execve(path, execute, envp);
        perror("execve");
    }

    // Parent
    close(fd[1]);
    if (i > 2) close(prev_fd);
    prev_fd = fd[0];
	i++;
}

}
