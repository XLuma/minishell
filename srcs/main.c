/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:47:03 by gasselin          #+#    #+#             */
/*   Updated: 2021/10/21 11:08:17 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_minishell	g_mini;

void	init_minishell(char **envp)
{
	char	*path;

	g_mini.env = ft_strarr_dup((char const **)envp, 0);
	g_mini.env_size = ft_strarr_size(g_mini.env);
	path = getenv("PATH");
	g_mini.path = ft_split(path, ':');
	g_mini.output_code = SUCCESS;
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**arg;

	(void) argc;
	(void) argv;
	init_minishell(envp);
	while (1)
	{
		line = readline("minishell-1.0$ ");
		if (ft_strlen(line) > 0)
		{
			add_history(line);
			arg = ft_split(line, ' ');
			free(line);
			if (ft_strcmp(arg[0], "export") == 0)
				ft_export(arg + 1);
			else if (ft_strcmp(arg[0], "unset") == 0)
				ft_unset(arg + 1);
			else if (ft_strcmp(arg[0], "env") == 0)
				ft_env(arg + 1);
			else if (ft_strcmp(arg[0], "echo") == 0)
				ft_echo(arg + 1);
			else if (ft_strcmp(arg[0], "pwd") == 0)
				ft_pwd();
			else if (ft_strcmp(arg[0], "cd") == 0)
				ft_cd(arg);
			else if (ft_strcmp(arg[0], "exit") == 0)
				ft_exit(arg);
			ft_strarr_free(arg);
		}
	}
	return (EXIT_SUCCESS);
}
