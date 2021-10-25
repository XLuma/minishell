/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:43:09 by gasselin          #+#    #+#             */
/*   Updated: 2021/10/25 17:15:49 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_args(t_token *token, const char *line, int *index)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (line[++j])
	{
		if (line[j] == 34 || line[j] == 39)
		{
			g_mini.open_quote = true;
			g_mini.char_quote = line[j];
			j++;
			while (line[j] && (g_mini.open_quote || !ft_iswhitespace(line[j])))
			{
				if (g_mini.open_quote && line[j] == g_mini.char_quote)
					g_mini.open_quote = false;
				if (!g_mini.open_quote && (line[j + 1] == 34 || line[j + 1] == 39))
				{
					j++;
					g_mini.open_quote = true;
					g_mini.char_quote = line[j];
				}
				j++;
			}
			token->cmd = ft_strarr_addback(token->cmd, ft_substr(line, i, j - i));
			i = j + 1;
		}
		else if (ft_iswhitespace(line[j]))
		{
			while (ft_iswhitespace(line[j]))
				j++;
			token->cmd = ft_strarr_addback(token->cmd, ft_substr(line, i, j - i));
			i = j;
			j--; 
		}
		if (!line[j])
			break ;
	}
	if (line[j] && !(ft_iswhitespace(line[ft_strlen(line) - 1])))
		token->cmd = ft_strarr_addback(token->cmd, ft_substr(line, i, j - i));
	index = &i;
}
