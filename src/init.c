/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:02:02 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/12 13:02:02 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "pipex_pipe.h"

int	init(t_pipex *pipex, int argc, char **argv)
{
	pipex->nb_cmd = argc - 3;
	pipex->paths = NULL;
	pipex->fd_infile = open(argv[1], O_RDONLY);
	if (pipex->fd_infile == -1)
		perror(argv[1]);
	pipex->fd_outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_outfile == -1)
		perror(argv[argc - 1]);
	if (create_pipes(pipex, argc) == 1)
	{
		perror("Pipe error");
		close(pipex->fd_infile);
		close(pipex->fd_outfile);
		return (1);
	}
	return (0);
}
