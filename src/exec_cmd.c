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
# include "pipex_pipe.h"
#include "pipex_cmd.h"
#include "pipex.h"

static char	**init_cmd(t_pipex *pipex, char **cmd, char *arg, char **envp)
{
	cmd = ft_split(arg, ' ');
	if (cmd == NULL)
		exit_child();
	cmd[0] = get_cmd_path(pipex, envp, cmd[0]);
	free_cmd(pipex->paths);
	free_pipex(pipex);
	if (cmd[0] == NULL)
	{
		free_cmd(cmd);
		exit_child();
	}
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
			close_pipes(pipex);
			exit_child();
		}
		close_pipes(pipex);
		cmd = init_cmd(pipex, cmd, arg, envp);
		execve(cmd[0], cmd, envp);
		perror("Execve error");
		exit_child();
	}
	return (0);
}
