#include <stdio.h>
#include "ft_pipex.h"
int main()
{
	int i;
	i = 0;
	while (i < 5)
	{
		int id;
		int fd[2];
		pipe(fd);
		id = fork();
		if (id == 0)
		{
			printf("%s\n", "First STDOUT");
			write(0, "deneme", ft_strlen("deneme"));
			dup2(fd[1], STDIN_FILENO);
			dup2(fd[0], STDOUT_FILENO);
			write(1, "deneme", ft_strlen("deneme"));
		}
		i++;
	}
	return 0;
}
