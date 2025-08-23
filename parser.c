/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:50:22 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/23 14:00:02 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
void	ft_free_str(char *str)
{
	free(str);
}
char	*ft_command_location(char const *av, char **envp)
{
	char	**path;
	char	*path_location;
	char	*command;
	char	*command_parsed;
	size_t i;
	size_t k;

	k = 0;
	i = 0;
	
	while (av[i] != '\0' && av[i] != ' ')
		i++;
	command = ft_substr(av, 0, i);
	while(envp[i] != NULL && ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	path = ft_split(envp[i], ':');
	while (path[k] != NULL)
	{
		command_parsed = ft_strjoin("/", command);
		path_location = ft_strjoin(path[k], command_parsed);
		
		i = access(path_location, F_OK);
		if (i == 0)
		{
			free(path);
			return (path_location);
		}
		else if (i < 0)
		{
			free(path);
			free(path_location);
		}
		k++;
	}
	i = 0;
	return (NULL);
}

int main(int ac, char **av, char **envp)
{
	char *path;
	path = ft_command_location(av[2], envp);
	printf("%s\n", path);
}
