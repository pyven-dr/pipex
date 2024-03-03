/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:52:17 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/29 00:52:17 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_cmd.h"

char	*get_cmd_path(t_pipex *pipex, char **envp, char *command)
{
	char	*path;
	char	*command_path;

	if (pipex->paths == NULL)
	{
		path = find_path(envp);
		pipex->paths = ft_split(path, ':');
		if (pipex->paths == NULL)
			return (free(command), NULL);
	}
	command_path = NULL;
	if (command != NULL)
		command_path = check_absolute_path(command);
	if (command_path == NULL && command != NULL)
		command_path = find_command(pipex->paths, command);
	else if (command_path == NULL)
		ft_putstr_fd("'': command not found\n", STDERR_FILENO);
	free(command);
	return (command_path);
}
