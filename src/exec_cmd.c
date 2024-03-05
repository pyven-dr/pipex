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

#include "pipex_exec.h"
#include "pipex_pipe.h"
#include "pipex_cmd.h"
#include "pipex.h"

static size_t	nb_arg(char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	return (i);
}

static char	**init_cmd(t_pipex *pipex, char **cmd, char *arg, char **envp)
{
	size_t	nb;

	cmd = ft_split(arg, ' ');
	if (cmd == NULL)
	{
		free_pipex(pipex);
		exit_child("Child error");
	}
	nb = nb_arg(cmd);
	cmd[0] = get_cmd_path(pipex, envp, cmd[0]);
	if (pipex->paths == NULL)
	{
		free_cmd(cmd);
		free(cmd);
		free_pipex(pipex);
		ft_putstr_fd("PATH not found\n", 2);
		exit_child(NULL);
	}
	free_cmd(pipex->paths);
	free(pipex->paths);
	free_pipex(pipex);
	check_cmd(nb, cmd);
	return (cmd);
}

int	exec_cmd(t_pipex *pipex, char *arg, int arg_nb, char **envp)
{
	char	**cmd;
	pid_t	id;

	cmd = NULL;
	id = fork();
	if (id < 0)
		return (perror("Fork error"), -1);
	if (id == 0)
	{
		if (dup_fd(pipex, arg_nb) == 1)
		{
			free_pipex(pipex);
			exit_child("Child error");
		}
		close_pipes(pipex);
		cmd = init_cmd(pipex, cmd, arg, envp);
		execve(cmd[0], cmd, envp);
		exit_child("Execve error");
	}
	return (0);
}
