/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 07:26:33 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/12 07:26:33 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
# include <errno.h>

typedef struct s_pipex
{
	char	**paths;
	int		(*fd)[2];
	int		nb_cmd;
	int		fd_infile;
	int		fd_outfile;
}	t_pipex;

char	*find_path(char	**envp);
char	*find_command(char **path, char *command);
char	*get_cmd_path(t_pipex *pipex, char **envp, char *command);
int		close_pipes(t_pipex *pipex);
int		create_pipes(t_pipex *pipex, int argc);
int		init(t_pipex *pipex, int argc, char **argv);
int		exec_cmd(t_pipex *pipex, char *arg, int arg_nb, char **envp);
void	free_pipex(t_pipex *pipex);

#endif
