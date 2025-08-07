/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:27:43 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/03 22:27:43 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
// Just testing the functions that are allowed
/* av[2] == "ls -la" 'daki "ls" bulmak için yapıldı ama split zaten bana bunu veriyor yinede dursun /usr/bin/---ls--  "ls -la"'daki "ls" bulmak için
size_t	ft_blank_is_found(char *av)
{
	size_t i;

	i = 0;
	while(av[i] != ' ' && av[i] != '\0')
		i++;
	return (i);
}*/
char	*ft_command(char const **av)
{

	char	*path;
	char	*path_location;
	char	**command;
	// Gerek yok ama yinede dursun split yaptığımız için command[0] path location'a gönderilebilir  size_t	av_substr_len;
	// av_substr_len = ft_blank_is_found(av[1]);

	path = "/usr/bin/";
	command = ft_split(av[0], ' ');
	path_location = ft_strjoin(path, command[0]);
	return (path_location);
}
// parse için ft_split Example av[2] == "ls -la veya ls -l" char **parse = ft_split(av[2], ' ') böylelikle char **parse = {"ls", "-l"}
// ./pipex infile -- infile pipex dosyaları içinde olsa yeterli mi ? yoksa infile aramam mı gerekiyor ??
// Commandler "ls -l -a" olabilir mi bunu handlelamamız gerekiyor mu ?
// Yoksa commandler "ls -la" mı olmak zorunda ?
int main(int ac, char const **av)
{
	char *path;
	char *command;
	char **command_to_ex;

	command = ft_strjoin(av[2], av[1]);
	printf("%s\n", command);
	command_to_ex = ft_split(command, ' ');
	path = ft_command(&av[2]);
	execve(path, command_to_ex, NULL);
	// execve(path_location, command, NULL);
	return 0;
}
