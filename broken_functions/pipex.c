/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:12:53 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/21 18:20:48 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
char	*ft_command_location(char const *av, char **envp)
{
	char	*path;
	char	*path_location;
	char	*command;
	size_t i;
	size_t k;

	k = 0;
	i = 0;

	while()
	while (av[i] != '\0' && av[i] != ' ')
		i++;
	command = ft_substr(av, 0, i);
	path_location = ft_strjoin(path, command);
	free (command);
	return (path_location);
}

int main(int ac, char const *av[], char **envp)
{
	int fd[2];
	char *command;
	char **execute;
	int id2;
	command = ft_command_location(av[2], envp);
	execute = ft_split(av[2], ' ');
	char *command_2;
	char **execute_2;
	command_2 = ft_command_location(av[3], envp);
	execute_2 = ft_split(av[3], ' ');
}