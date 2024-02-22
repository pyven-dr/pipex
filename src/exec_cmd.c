/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:06:16 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/18 00:06:16 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

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

int	exec_cmd(t_pipex *pipex, char *arg, int arg_nb, char **envp)
{
	char	**cmd;
	pid_t	id;
	char	*cmd_path;

	id = fork();
	if (id < 0)
		return (perror("Fork error"), -1);
	if (id == 0)
	{
		cmd = ft_split(arg, ' ');
		if (cmd == NULL)
			exit(1);
		if (dup_fd(pipex, arg_nb) == 1)
		{
			free_cmd(cmd);
			exit(1);
		}
		close_pipes(pipex);
		cmd_path = get_cmd_path(pipex, envp, cmd[0]);
		free_cmd(pipex->paths);
		free_pipex(pipex);
		if (cmd_path == NULL)
		{
			close(1);
			close(0);
			free_cmd(cmd);
			exit(1);
		}
		execve(cmd_path, cmd, envp);
		perror("Execve error");
		exit(1);
	}
	return (0);
}
