/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:56:54 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/27 13:58:17 by bahkaya          ###   ########.fr       */
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
	if ((infile < 0 || outfile < 0))
		return (0);
	ft_pipe_exc(av, envp, ac, infile, outfile);
	close(infile);
	close(outfile);
}

