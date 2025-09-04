/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:31:47 by bahkaya           #+#    #+#             */
/*   Updated: 2025/09/04 15:33:55 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_free_str(char *str)
{
	free(str);
}

static void	ft_free_split(char **arr, size_t k)
{
	while (arr[k] != NULL)
	{
		free(arr[k]);
		k++;
	}
	free(arr);
}

static char	*ft_find_command(char const *av)
{
	char	*command;
	char	*command_parsed;
	int		i;

	i = 0;
	if (access(av, F_OK | X_OK) == 0)
		return (ft_strdup(av));
	while (av[i] != '\0' && av[i] != ' ')
		i++;
	command = ft_substr(av, 0, i);
	command_parsed = ft_strjoin("/", command);
	free(command);
	return (command_parsed);
}

static char	*ft_find_path_location(char **path, char *command_parsed)
{
	char	*path_location;
	int		i;
	size_t	k;

	i = 0;
	k = 0;
	while (path[k] != NULL)
	{
		path_location = ft_strjoin(path[k], command_parsed);
		i = access(path_location, F_OK);
		if (i == 0)
		{
			ft_free_str(command_parsed);
			ft_free_split(path, k);
			return (path_location);
		}
		else if (i < 0)
		{
			free(path[k]);
			free(path_location);
		}
		k++;
	}
	return (NULL);
}

char	*ft_command_location(char const *av, char **envp)
{
	char	**path;
	char	*path_location;
	char	*command_parsed;
	int		i;
	size_t	k;

	k = 0;
	i = 0;
	if (access(av, X_OK | F_OK) == 0)
		return (ft_strdup(av));
	command_parsed = ft_find_command(av);
	while (envp[i] != NULL && ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	path = ft_split(envp[i], ':');
	path_location = ft_find_path_location(path, command_parsed);
	if (!path_location)
		return (NULL);
	return (path_location);
}
