/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argnb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:54:26 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/02/29 00:54:26 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_argnb(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("Syntax error : not enough arguments\n", 2);
		exit(2);
	}
}
