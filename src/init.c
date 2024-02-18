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

int	init(t_pipex *pipex, int argc, char **argv)
{
	pipex->nb_cmd = argc - 3;
	pipex->paths = NULL;
	pipex->fd_infile = open(argv[1], O_RDONLY);
	if (pipex->fd_infile == -1)
		return (perror("Infile error"), 1);
	pipex->fd_outfile = open(argv[argc - 1], O_WRONLY);
	if (pipex->fd_outfile == -1)
	{
		perror("Outfile error");
		close(pipex->fd_infile);
		return (1);
	}
	if (create_pipes(pipex, argc) == -1)
	{
		perror("Pipe error");
		close(pipex->fd_infile);
		close(pipex->fd_outfile);
		return (1);
	}
	return (0);
}
