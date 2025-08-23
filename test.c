#include "ft_pipex.h"
int main(int ac, char **av, char **envp)
{
	int i;
	i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
