/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 07:25:09 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/12 07:25:09 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		i;

	i = 0;
	pipex = malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (1);
	init(pipex, argc, argv);
	if (pipex->fd_infile == -1)
		i++;
	if (pipex->fd_outfile == -1)
		argc--;
	while (i < argc - 3)
	{
		exec_cmd(pipex, argv[i + 2], i, envp);
		i++;
	}
	free_pipex(pipex);
	while (wait(NULL) >= 0)
		;
	return (0);
}

/*int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	int file = open("test.txt", O_WRONLY);
	printf("%d\n", access("/usr/bin/cat", F_OK));
	dup2(file, 1);
	close(file);
	char *args[3];
	args[0] = "/usr/bin/cat";
	args[1] = "./src/main.c";
	args[2] = NULL;
	int id = fork();
	if (id == 0)
		execve(args[0], args, envp);
	wait(NULL);
	printf("test %d\n", id);
	return (0);
}*/