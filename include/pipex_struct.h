/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:59:53 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/29 00:59:53 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCT_H
# define PIPEX_STRUCT_H

typedef struct s_pipex
{
	char	**paths;
	int		(*fd)[2];
	int		nb_cmd;
	int		fd_infile;
	int		fd_outfile;
}	t_pipex;

#endif
