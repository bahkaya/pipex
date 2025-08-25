/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borular_tutuldu_mu_qardas.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:27:11 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/25 19:05:28 by bahkaya          ###   ########.fr       */
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
	if (ac > 1)
	{
		file = open("pipex.c", O_RDONLY, 0644);
		char *p = "/usr/bin/ls";
		char **exc = {"ls", NULL};
		dup2(STD, )
		
		

		return (0);
	}
	else return(0);
}