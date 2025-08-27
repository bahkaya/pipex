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


