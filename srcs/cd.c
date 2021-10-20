/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:38:08 by gasselin          #+#    #+#             */
/*   Updated: 2021/10/20 10:22:46 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(char **argv)
{
	g_mini.output_code = SUCCESS;
	if (!argv[1])
	{
		if (ft_getenv("HOME") == NULL)
			print_error("cd", NULL, NO_HOME, GEN_ERR);
		else if (chdir(ft_getenv("HOME=")) == -1)
			print_error("cd", strerror(errno), ft_getenv("HOME"), GEN_ERR);
		else
			modify_env(ft_getenv("HOME"));
	}
	else
	{
		if (argv[2])
			print_error("cd", NULL, ARGS_ERR, GEN_ERR);
		else if (chdir(argv[1]) == -1)
			print_error("cd", strerror(errno), argv[1], GEN_ERR);
		else
			modify_env(argv[1]);
	}
}