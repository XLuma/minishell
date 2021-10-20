/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:47:03 by gasselin          #+#    #+#             */
/*   Updated: 2021/10/20 13:22:44 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_minishell g_mini;

void	init_minishell(char **envp)
{
	char		*path;
	
	g_mini.env = ft_strarr_dup((char const **)envp, 0);
	g_mini.env_size = ft_strarr_size(g_mini.env);
	path = getenv("PATH");
	g_mini.path = ft_split(path, ':');
	g_mini.output_code = SUCCESS;
}

int	main(int argc, char **argv, char **envp)
{
	// char	path[PATH_MAX];
	char	*line;
	// char	**cmd;
	char	**arg;
	
	(void) argc;
	(void) argv;
	init_minishell(envp);
	arg = malloc(4 * sizeof(char *));
	arg[0] = ft_strdup("0=0");
	arg[1] = ft_strdup("1=1");
	arg[2] = ft_strdup("C=2");
	arg[3] = NULL;
	while (1)
	{
		line = readline("minishell-1.0$ ");
		if (ft_strlen(line) > 0)
		{
			add_history(line);
			// cmd = ft_split(line, '|');
			if (ft_strcmp(line, "export") == 0)
			{
				ft_export(arg);
				arg[0] = NULL;
				ft_export(arg);
			}
			else if (ft_strcmp(line, "env") == 0)
			{
				ft_env(arg + 1);
			}
			else if (ft_strcmp(line, "exit") == 0)
			{
				free (line);
				printf("exit\n");
				// rl_clear_history();
				break ;
			}
		}
		free (line);
	}
	return (EXIT_SUCCESS);
}