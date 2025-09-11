/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:56:54 by bahkaya           #+#    #+#             */
/*   Updated: 2025/09/05 15:11:05 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int main(int ac, char const *av[], char **envp)
{
	if (ac == 5)
	{
	int infile;
	infile = open(av[1], O_RDONLY, 0644);
	if (infile < 0)
		return (0);
	ft_pipe_exc(av, envp, ac, infile);
	}
	else
		write(1, "\n", 1);
}
