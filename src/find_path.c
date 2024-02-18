/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 07:33:45 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/12 07:33:45 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char	**envp)
{
	size_t	i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	return (envp[i] + 5);
}

char	*find_command(char **path, char *command)
{
	size_t	i;
	char	*command_path;
	char	*temp;

	i = 0;
	while (path[i])
	{
		temp = ft_strjoin("/", command);
		if (temp == NULL)
			return (NULL);
		command_path = ft_strjoin(path[i], temp);
		free(temp);
		if (command_path == NULL)
			return (NULL);
		if (access(command_path, F_OK) == 0)
			return (command_path);
		free(command_path);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(t_pipex *pipex, char **envp, char *command)
{
	char	*path;

	if (pipex->paths == NULL)
	{
		path = find_path(envp);
		pipex->paths = ft_split(path, ':');
		if (pipex->paths == NULL)
			return (NULL);
	}
	return (find_command(pipex->paths, command));
}
