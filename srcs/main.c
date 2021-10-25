/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:47:03 by gasselin          #+#    #+#             */
/*   Updated: 2021/10/25 17:14:01 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_minishell	g_mini;

void	init_minishell(char **envp)
{
	char	*path;

	g_mini.env = ft_strarr_dup(envp, 0);
	g_mini.env_size = ft_strarr_size(g_mini.env);
	path = getenv("PATH");
	g_mini.path = ft_split(path, ':');
	g_mini.output_code = SUCCESS;
	g_mini.output_code = false;
	g_mini.char_quote = 0;
}

void	parse_cmds(char **arg)
{
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
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_token	token;
	int		i;

	(void) argc;
	(void) argv;
	token.prev = NULL;
	token.next = NULL;
	token.cmd = NULL;
	// line = "echo 'Broche    a'123'foin'";
	init_minishell(envp);
	while (1)
	{
		line = readline("minishell-1.0$ ");
		if (ft_strlen(line) > 0)
		{
			add_history(line);
			parse_args(&token, (const char *)line, &i);
			// char *str = ft_strtrim(token.cmd[0], WHITESPACES);
			// free (token.cmd[0]);
			// token.cmd[0] = str;
			free(line);
			parse_cmds(token.cmd);
			ft_strarr_free(token.cmd);
		}
	}
	return (EXIT_SUCCESS);
}
