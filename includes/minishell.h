/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:46:28 by gasselin          #+#    #+#             */
/*   Updated: 2021/10/21 10:22:54 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# define NO_HOME "HOME not set"
# define NO_FLDIR "No such file or directory"
# define ARGS_ERR "too many arguments"
# define NO_IDENT "not a valid identifier"
# define NUM_ERR "numeric argument required"

# define SUCCESS 0
# define GEN_ERR 1
# define EXIT_ERR 255

# define NAMESET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_"

typedef struct s_minishell
{
	char		**env;
	char		**path;
	int			env_size;
	long int	output_code;
}	t_minishell;

extern t_minishell g_mini;

void	ft_echo(char **argv);
void	ft_cd(char **argv);
void	ft_env(char **argv);
void	ft_export(char **argv);
void	ft_unset(char **argv);
void	ft_pwd(void);
void	ft_exit(char **argv);

char	*ft_getenv(const char *name);
int		ft_setenv(const char *name, const char *value, int overwrite);
void	ft_addenv(const char *name, const char *value);

void	print_error(const char *v1, const char *v2, const char *v3, int code);

#endif