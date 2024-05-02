/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:03:14 by fcarranz          #+#    #+#             */
/*   Updated: 2024/05/02 14:24:44 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void	call_execve(char *cmd)
{
	char	*args[] = { cmd, "Makefile", NULL };

	execve(cmd, args, NULL);
	perror("Error ejecutando execve\n");
	exit(EXIT_FAILURE);
}


int	main(int argc, char **argv)
{
	pid_t	pid;
	int		fds[2];
	char	buffer[20] = { 0 };

	if (argc < 2)
		return (perror("TO FEW ARGUMENTS\n"), 1);
	if (pipe(fds)) // This has to happen before fork so the two process can share the pipe
		return (perror("CANT CREATE THE PIPE"), 1);
	pid = fork();
	if (pid == 0)
	{
		printf("Child process here with ID: %d.\n",	getpid());
		close(fds[0]);
		write(fds[1], "Hello World", 12);
		close(fds[1]);
		return (0);
	}
	else
	{
		wait(NULL);
		printf("Parent process here. My PID is %d. My child has left. his process ID was %d\n", getpid(), pid);
		close(fds[1]);
		read(fds[0], buffer, 20);
		close(fds[0]);
		printf("Child process left this message: \"%s\"\n", buffer);
	}
	printf("Parent here again! Child has finished. I still have PID %d.\n", getpid());
		call_execve(argv[1]);
	return (0);
}
