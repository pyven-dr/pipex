/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:53:19 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/18 00:53:19 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_pipe.h"
#include "pipex.h"

void	free_pipex(t_pipex *pipex)
{
	close_pipes(pipex);
	free(pipex->fd);
	free(pipex);
}

void	free_cmd(char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
}
