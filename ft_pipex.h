/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:26:48 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/03 22:26:48 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PIPEX
#define FT_PIPEX

#include "./libft/libft.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_free_str(char *str);
void	ft_free_split(char **arr, size_t k);
char	*ft_find_command(char const *av);
char	*ft_command_location(char const *av, char **envp);
char	*ft_find_path_location(char **path, char *command_parsed);
void	ft_pipe_exc(char const **av, char **envp, int ac, int infile, int outfile);

#endif