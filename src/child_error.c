/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:46:58 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/29 00:46:58 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_exec.h"

void	exit_child(char *error)
{
	close(0);
	close(1);
	if (error != NULL)
		perror(error);
	exit(1);
}

void	check_cmd(size_t nb, char **cmd)
{
	if (cmd[0] == NULL && nb > 0)
	{
		free_cmd(cmd + 1);
		free(cmd);
		close(0);
		close(1);
		exit(1);
	}
	else if (cmd[0] == NULL && nb == 0)
	{
		free(cmd);
		close(0);
		close(1);
		exit(1);
	}
}