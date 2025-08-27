/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borular_tutuldu_mu_qardas.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:27:11 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/26 12:31:42 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int main(int ac, char **av)
{
	int fd[2];
	int i;
	i = 1;
	int file;
	ssize_t k;
	pipe(fd);
	char buffer[1024];
	if (ac > 1)
	{
		
		file = open("pipex.c", O_RDONLY, 0644);
		dup2(fd[1], file);
		while (k != 0)
		{
			k = read(fd[0], buffer, 1);
			printf("%s\n", buffer);
		}
		close(fd[0]);
		close(fd[1]);
		return (0);
	}
	else return(0);
}