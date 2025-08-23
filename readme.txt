Function	Shell Command Equivalent
open	Handled implicitly when you use cat file.txt, > or < for redirection.
close	Automatically done in shell; not directly exposed.
read	read (in bash) reads a line from input (not exactly syscall read, but similar).
write	echo "text" > file.txt or printf writes to files.
malloc	Not applicable in shell; handled internally in programs.
free	Not applicable in shell; memory management is hidden.
perror	echo $? shows last command's exit status; errors are usually printed automatically.
strerror	Not directly available; error messages shown automatically.
access	test -r file, test -w file, test -x file, or [ -r file ] etc.
dup	Not directly in shell; shell redirection (2>&1) relies on it under the hood.
dup2	command 2>&1 redirects stderr to stdout using file descriptor duplication.
execve	exec ./program replaces current shell process with the program.
exit	exit exits the shell or script.
fork	Shell spawns subshells or processes with commands run in background (&).
pipe	`command1
unlink	rm file.txt removes (unlinks) a file.
wait	wait waits for background jobs to finish in a shell script.
waitpid	wait <pid> waits for a specific PID.

Commandler "ls -l -a" olabilir mi bunu handlelamamız gerekiyor mu ?
Yoksa commandler "ls -la" mı olmak zorunda ?


void	command_to_execute(int *fd, const char *av, char **execute, char *command)
{
	close(fd[0]);
	int infile = open(av, O_RDONLY, 0666);
	dup2(infile , STDIN_FILENO);
	dup2(fd[1] , STDOUT_FILENO);
	close(infile);
	close(fd[1]);
	execve(command, execute, NULL);
}
int main(int ac, char const *av[])
{
	int fd[2];
	char *command;
	char **execute;
	int id2;
	char *command_2;
	char **execute_2;

	command = ft_command_location(av[2]);
	execute = ft_split(av[2], ' ');
	command_2 = ft_command_location(av[3]);
	execute_2 = ft_split(av[3], ' ');
	if (pipe(fd) == -1)
	{
		return (1);
	}
	int id = fork();
	if (id == 0)
	{
		command_to_execute(fd, av[1], execute, command);
	}
	if (id != 0)
	{
		id2 = fork();
	}
	if (id2 == 0)
	{
		command_to_execute(fd, av[4], execute_2, command);
	}
	{
		
		int i;
	
		i = 0;
		while(execute[i] != NULL || execute_2[i] != NULL)
		{
			free(execute[i]);
			free(execute_2[i]);
			i++;
		}
		free(execute);
		free(execute_2);
		free(command);
		free(command_2);
		close(fd[0]);
		close(fd[1]);
	}
	return 0;
}