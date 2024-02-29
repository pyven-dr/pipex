/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:58:10 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/29 00:58:10 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_CMD_H
# define PIPEX_CMD_H

# include "pipex_struct.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

char	*find_path(char	**envp);
char	*find_command(char **path, char *command);
char	*get_cmd_path(t_pipex *pipex, char **envp, char *command);
char	*check_absolute_path(char *cmd);

#endif
