/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipe.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:25:29 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/29 02:25:29 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_PIPE_H
# define PIPEX_PIPE_H

# include "pipex_struct.h"
# include <stdlib.h>
# include <unistd.h>

int	close_pipes(t_pipex *pipex);
int	create_pipes(t_pipex *pipex, int argc);

#endif
