/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:20:38 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/12 12:20:38 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->fd_infile != -1)
		close(pipex->fd_infile);
	if (pipex->fd_outfile != -1)
		close(pipex->fd_outfile);
	while (i < pipex->nb_cmd - 1)
	{
		close(pipex->fd[i][0]);
		close(pipex->fd[i][1]);
		i++;
	}
	return (0);
}

int	create_pipes(t_pipex *pipex, int argc)
{
	int	i;

	i = 0;
	pipex->fd = malloc(sizeof(int [2]) * argc - 4);
	if (pipex->fd == NULL)
		return (1);
	while (i < argc - 4)
	{
		if (pipe(pipex->fd[i]) < 0)
		{
			while (i - 1 <= 0)
			{
				close(pipex->fd[i - 1][0]);
				close(pipex->fd[i - 1][1]);
				i--;
			}
			free(pipex->fd);
			return (1);
		}
		i++;
	}
	return (0);
}
