/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:28:13 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/29 02:28:13 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_EXEC_H
# define PIPEX_EXEC_H

# include "pipex_struct.h"
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		dup_fd(t_pipex *pipex, int arg_nb);
int		exec_cmd(t_pipex *pipex, char *arg, int arg_nb, char **envp);
void	free_cmd(char **cmd);
void	exit_child(void);
void	check_cmd(size_t nb, char **cmd);

#endif
