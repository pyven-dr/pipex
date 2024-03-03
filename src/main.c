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
#include "pipex_exec.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		i;

	check_argnb(argc);
	i = 0;
	pipex = malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (1);
	if (init(pipex, argc, argv) == 1)
		return (free(pipex), 1);
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
