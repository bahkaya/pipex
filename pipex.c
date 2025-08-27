/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:56:54 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/27 12:29:42 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"


int main(int ac, char const *av[], char **envp)
{
	int infile;
	int outfile;
	int i;
	i = 2;
	infile = open(av[1], O_RDONLY, 0644);
	outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if ((infile == -1 || outfile == -1))
		return (0);
	while (i < ac - 1)
	{
		ft_pipe_exc(av, envp, ac, infile, outfile, i);
		i++;
	}
	close(infile);
	close(outfile);
}

