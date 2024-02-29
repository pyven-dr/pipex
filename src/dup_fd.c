/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:44:21 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/29 00:44:21 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_exec.h"

int	dup_fd(t_pipex *pipex, int arg_nb)
{
	int	fd1;
	int	fd2;

	if (arg_nb == 0)
	{
		fd1 = dup2(pipex->fd_infile, STDIN_FILENO);
		fd2 = dup2(pipex->fd[0][1], STDOUT_FILENO);
	}
	else if (arg_nb == pipex->nb_cmd - 1)
	{
		fd1 = dup2(pipex->fd[arg_nb - 1][0], STDIN_FILENO);
		fd2 = dup2(pipex->fd_outfile, STDOUT_FILENO);
	}
	else
	{
		fd1 = dup2(pipex->fd[arg_nb - 1][0], STDIN_FILENO);
		fd2 = dup2(pipex->fd[arg_nb][1], STDOUT_FILENO);
	}
	if (fd1 < 0 || fd2 < 0)
	{
		perror("Dup2 Error");
		return (1);
	}
	return (0);
}
