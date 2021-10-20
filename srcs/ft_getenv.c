/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:13:36 by gasselin          #+#    #+#             */
/*   Updated: 2021/10/20 11:54:22 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_addenv(const char *name, const char *value)
{
	char	**env;
	char	*str;

	env = ft_strarr_dup((const char **)g_mini.env, 1);
	ft_strarr_free(g_mini.env);
	g_mini.env = env;
	g_mini.env[g_mini.env_size] = ft_strdup(name);
	if (value)
	{
		free (g_mini.env[g_mini.env_size]);
		str = ft_strjoin_triple(name, "=", value);
		g_mini.env[g_mini.env_size] = str;
	}
	g_mini.env[g_mini.env_size + 1] = NULL;
	g_mini.env_size = ft_strarr_size(g_mini.env);
}

void	modify_env(char *path)
{
	int	i;
	char	*pwd;
	char	*newpath;

	i = 0;
	pwd = ft_getenv("PWD");
	if (pwd == NULL)
		pwd = ft_strdup("");
	if (!ft_getenv("OLDPWD"))
		ft_addenv("OLDPWD", pwd);
	if (ft_strcmp(path, ft_getenv("HOME")) == 0)
		newpath = path;
	i = ft_strarr_index(g_mini.env, "OLDPWD=");
	if (i >= 0)
	{
		free (g_mini.env[i]);
		g_mini.env[i] = ft_strjoin("OLDPWD=", pwd);
	}
	i = ft_strarr_index(g_mini.env, "PWD=");
	if (i >= 0)
	{
		free (g_mini.env[i]);
		g_mini.env[i] = ft_strjoin("PWD=", newpath); // Current folder
	}
}

int	ft_setenv(const char *name, const char *value, int overwrite)
{
	char	*str;
	int		i;

	if (name == NULL || ft_strlen(name) == 0 || ft_strchr(name, '='))
		return (-1);
	if (ft_getenv(name) && overwrite == 0)
		return (0);
	if (ft_getenv(name) == NULL)
	{
		ft_addenv(name, value);
		return (0);
	}
	str = ft_strjoin(name, "=");
	i = ft_strarr_index(g_mini.env, str);
	if (value && overwrite)
	{
		free (g_mini.env[i]);
		g_mini.env[i] = ft_strjoin(str, value);
	}
	free (str);
	return (0);
}

char	*ft_getenv(const char *name)
{
	int		i;
	char	*str;
	size_t	size;

	i = 0;
	str = ft_strjoin(name, "=");
	size = ft_strlen(str);
	while (g_mini.env[i] != NULL)
	{
		if (ft_strncmp(g_mini.env[i], str, size) == 0)
		{
			free (str);
			return (g_mini.env[i] + size);
		}
		i++;
	}
	free (str);
	return (NULL);
}